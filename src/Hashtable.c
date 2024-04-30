#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include "../include/Hashtable.h"

#define FNV_OFFSET 14695981039346656037UL
#define FNV_PRIME 1099511628211UL

static uint64_t hash_key(const char* key) {
    uint64_t hash = FNV_PRIME;

    for(const char* p = key; *p; p++) {
        hash ^= (uint64_t)(unsigned char)(*p);
        hash *= FNV_PRIME;
    }

    return hash;
}

static void insert_item(Item* list, int capacity, char* key, void* value, int* size) {
    uint64_t hash = hash_key(key);
    int index = (int)(hash & ((uint64_t)capacity - 1));

    while(list[index].key) {
        if(list[index].key == key) {
            list[index].value = value;
            return;
        }

        printf("Collision between %s and %s\n", key, list[index].key);
        index++;
        if(index >= capacity) {
            index = 0;
        }
    }

    if(size) {
        if(!key) return;
        (*size)++;
    }

    list[index].key = key;
    list[index].value = value;
}

void resize(Dict* dict) {
    int new_capacity = dict->capacity * 2;
    if(new_capacity < dict->capacity) return;

    Item* new_items = calloc(dict->capacity, sizeof(Item));
    if(!new_items) return;

    Item item;
    for(int i = 0; i < dict->capacity; i++) {
        item = dict->items[i];
        if(item.key) {
            insert_item(dict->items, dict->capacity, item.key, item.value, NULL);
        }
    }

    free(dict->items);
    dict->items = new_items;
    dict->capacity= new_capacity;
}

Dict* dict_create() {
   printf("Allocating memory for hashtable.\n");
    Dict* dict = (Dict*) malloc(sizeof(Dict));
    if(!dict) {
        perror("Memory error\n");
        return NULL;
    }

    printf("Initilizing hashtable variables.\n");
    dict->size = 0;
    dict->capacity = START_CAP;

    printf("Allocating memory for table entries.\n");
    dict->items = calloc(dict->capacity, sizeof(Item));
    if(dict->items == NULL) {
        free(dict);
        perror("Memory error\n");
        return NULL;
    }

    return dict;
}

void dict_destroy(Dict** dict) {
    printf("Deleting items from table\n");
    free((*dict)->items);
    (*dict)->items = NULL;

    printf("Deleting hashtable\n");
    free(*dict);
    (*dict) = NULL;
}

void dict_insert(Dict* dict, char* key, void* value) {
    if(!dict) return;

    if(dict->size >= dict->capacity / 2)
        resize(dict);

    insert_item(dict->items, dict->capacity, key, value, &dict->size);
}

void* dict_get(Dict* dict, char* key) {
    if(!dict) return NULL;
    uint64_t hash = hash_key(key);
    int index = (int)(hash & ((uint64_t)dict->capacity - 1));

    while(dict->items[index].key) {
        if(dict->items[index].key == key)
            return dict->items[index].value;

        index++;
        if(index >= dict->capacity)
            index = 0;
    }

    return NULL;
}

void dict_remove(Dict* dict, char* key) {
    if(!dict) return;
    uint64_t hash = hash_key(key);
    int index = (int)(hash & ((uint64_t)dict->capacity - 1));

    while(dict->items[index].key) {
        if(dict->items[index].key == key) {
            dict->items[index].key = NULL;
            dict->items[index].value = NULL;
            return;
        }

        index++;
        if(index >= dict->capacity)
            index = 0;
    }
}

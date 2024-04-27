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
    Dict* temp = *dict;

    printf("Freeing hashtable from memory.\n");
    free(temp->items);
    temp->items = NULL;

    free(*dict);
    (*dict) = NULL;
}

int dict_insert(Dict* dict, char* key, void* value) {
    if(!dict) return -1;

    int index = hash_key(key) % dict->capacity;
    int collision = 1;

    while(collision) {
        if(!dict->items[index].key) {
            dict->items[index].key = key;
            dict->items[index].value = value;

            collision = 0;
        } else if(dict->items[index].key == key) {
            dict->items[index].value = value;

            collision = 0;
        }

        if(index == dict->capacity - 1)
            index = 0;
        else
            index++;

    }

    return 0;
}

void* dict_get(Dict* dict, char* key) {
    if(!dict) return NULL;

    int index = hash_key(key) % dict->capacity;
    int exit = 1;
    int count = 0;

    while(exit) {
        if(dict->items[index].key == key)
            return dict->items[index].value;

        if(index == dict->capacity - 1)
            index = 0;
        else
            index++;

        if(count == dict->capacity - 1)
            return NULL;

        count++;
    }
}

int dict_remove(Dict* dict, char* key) {
    if(!dict) return -1;

    int index = hash_key(key) % dict->capacity;
    int exit = 1;
    int count = 0;

    while(exit) {
        if(dict->items[index].key == key) {
            dict->items[index].key = NULL;
            dict->items[index].value = NULL;

            return 1;
        }

        if(index == dict->capacity - 1)
            index = 0;
        else
            index++;

        if(count == dict->capacity - 1)
            return -1;

        count++;
    }
}

#include <stdint.h>

#define START_CAP 16

typedef struct Item {
    char* key;
    void* value;
} Item;

typedef struct Dict {
    struct Item* items;
    int size;
    int capacity;
} Dict;

Dict* dict_create();
void dict_destroy(Dict**);

void* dict_get(Dict* dict, char* key);
void dict_insert(Dict*, char*, void*);
void dict_remove(Dict* dict, char* key);

// Make these static eventually
//uint64_t hash_key(const char* key);
//void resize(Dict* dict);
//void item_insert(Item* list, );

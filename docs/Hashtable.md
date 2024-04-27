# HashTables

Hashtables consist of an array but aren't accessed like normal arrays.
We take a key, hash it and then index it to an array.
The value stored there is accessed via the key.

There are possibilties for colisions so we must check to see if the slot
over is available. If it isn't available check the next one until
there is one available. This is called linear probing.

The array consist of a struct of key, value pairs.

struct item {
    char* key;
    void* value;
};

And we will define a struct to hold the array and data related.

struct dict {
    item* table;
    int capacity;
    int size;
}

The hashtable has a couple main functions and a few helper functions.
Main functions to get, insert and remove values.
And helper functions to hash keys and resize the array.

int insert(dict ptr, key, value);

void ptr get(dict ptr, key);

void delete(dict, key);

int hash(key);

resize(dict, size);

## Insert funcion

The insert function has a couple of responsibilites.

1. Hash key and map to table array.
2. Check to see if the index at map is occupied.
3. If occupied check to see if keys match.
4. If not increase index by one and repeat step 2.
5. If index at map is not occupied insert into index.

typedef struct ListEntry {
    void* value;
    struct ListEntry* next;
} ListEntry;

typedef struct LinkedList {
    ListEntry* head;
    ListEntry* tail;
    int length;
} LinkedList;

// Constructor and destructor for list entry
ListEntry* listEntry_Create(void*);
void listEntry_Destroy(ListEntry*);

// Constructor and destructor for linked list
LinkedList* linkedList_Create();
void linkedList_Destroy(LinkedList*);

// Is the linked list empty
int linkedList_Empty(LinkedList*);

// Insert a value at the start of the list
void linkedList_Prepend(LinkedList*, void*);

// Insert a value at the end of the list
void linkedList_Append(LinkedList*, void*);

// Remove and return the end of the list
//ListEntry* linkedList_Pop(LinkedList*);

// Remove and return the start of the list
//ListEntry* linkedList_Chop(LinkedList*);

// Find and return the entry of the value
//ListEntry* linkedList_Get(LinkedList*, void*);

// Find and remove the entry of the value
// void linkedList_Remove(LinkedList*, void*);

// Print the list
void linkedList_Print(LinkedList*);

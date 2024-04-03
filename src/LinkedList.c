#include "../include/LinkedList.h"
#include <stdlib.h>
#include <stdio.h>

ListEntry* listEntry_Create(void* value) {
    ListEntry* entry = (ListEntry*) malloc(sizeof(ListEntry));
    if(!entry) NULL;

    entry->value = value;
    entry->next = NULL;

    return entry;
}

void listEntry_Destroy(ListEntry* entry) {
    printf("Destroying entry with value of %d\n", *(int*)entry->value);
    free((void*)entry);
}

LinkedList* linkedList_Create() {
    LinkedList* list = (LinkedList*) malloc(sizeof(LinkedList));
    if(!list) return NULL;

    list->head = NULL;
    list->tail = NULL;
    list->length = 0;

    return list;
}

void linkedList_Destroy(LinkedList* list) {
    ListEntry* head = list->head;
    ListEntry* temp;

    while(head) {
        temp = head;
        head = head->next;
        listEntry_Destroy(temp);
    }

    printf("Destroying list\n");
    free((void*)list);
}

int linkedList_Empty(LinkedList* list) {
    if(list->length == 0) return 0;

    return 1;
}

void linkedList_Prepend(LinkedList* list, void* value) {
    ListEntry* entry = listEntry_Create(value);
    if(!entry) return;

    if(list->head = NULL) {
        list->head = entry;
        list->tail = entry;
    } else {
        entry->next = list->head;
        list->head = entry;
    }

    ++list->length;
}

void linkedList_Append(LinkedList* list, void* value) {
    if(!list) return;

    ListEntry* entry = listEntry_Create(value);
    if(!entry) return;

    if(list->head == NULL) {
        list->head = entry;
        list->tail = entry;
    } else {
        list->tail->next = entry;
        list->tail = entry;
    }

    ++list->length;
}

void linkedList_Print(LinkedList* list) {
    ListEntry* current = list->head;

    printf("Printing list:\n");

    printf("[ ");
    while(current) {
        if(current->next) printf("%d, ", *(int*)current->value);
        else printf("%d ", *(int*)current->value);
        current = current->next;
    }

    printf("]\n");
}

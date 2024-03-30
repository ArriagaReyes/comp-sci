#include <stdlib.h>
#include "../include/LinkedList.h"
#include "../include/Queue.h"

#define TRUE  1
#define FALSE 0

int empty(struct LinkedList* list) {
    if(list->head)
        return FALSE;
    return TRUE;
}

void enqueue(struct LinkedList* list, int value) {
    append(list, value);
}

struct ListNode* dequeue(struct LinkedList* list) {
    if(list->head == NULL)
        return NULL;
    struct ListNode* node = list->head;

    list->head = list->head->next;
    node->next = NULL;

    return node;
}

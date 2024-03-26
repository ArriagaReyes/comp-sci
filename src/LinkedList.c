#include "../include/LinkedList.h"
#include <stdlib.h>
#include <stdio.h>

struct ListNode* createNode(int value) {
    struct ListNode* node =
        (struct ListNode*) malloc(sizeof(struct ListNode));
    if(node == NULL)
        return NULL;

    node->next = NULL;
    node->value = value;

    return node;
}

struct LinkedList* createList(int array[], int size) {
    struct LinkedList* list =
        (struct LinkedList*) malloc(sizeof(struct LinkedList));
    if(list == NULL)
        return NULL;

    int i = 0;
    while(i < size) {
        append(list, array[i]);
        ++i;
    }

    return list;
}

struct ListNode* find(struct LinkedList* list, int value) {
    if(list->head == NULL)
        return NULL;

    struct ListNode* current = list->head;

    while(current->next != NULL) {
        if(current->value == value)
            return current;
        current = current->next;
    }

    return NULL;
}

void append(struct LinkedList* list, int value) {
    struct ListNode* node = createNode(value);

    if(list->head == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }
}

void prepend(struct LinkedList* list, int value) {
    struct ListNode* node = createNode(value);

    node->next = list->head;
    list->head = node;
}

void insert(struct ListNode* before, struct ListNode* after, int value) {
    struct ListNode* node = createNode(value);
    struct ListNode* temp;

    if(before != NULL && after != NULL) {
        temp = after;

        before->next = node;
        node->next = temp;
    } else if(after == NULL) {
        before->next = node;
    }
}

void printList(struct LinkedList* list) {
    struct ListNode* current = list->head;

    printf("Printing list: \n");
    while(current != NULL) {
        printf("Value: %d\n", current->value);
        current = current->next;
    }
}

/*void printList(struct ListNode* head) {
    struct ListNode* current = head;

    printf("Printing list:\n");
    while(current != NULL) {
        printf("Value: %d\n", current->value);
        current = current->next;
    }
}*/
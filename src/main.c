#include <stdio.h>
#include <stdlib.h>
#include "../include/LinkedList.h"

struct ListNode* find(struct ListNode* head, int value) {
    struct ListNode* current = head;

    while(current->next != NULL) {
        if(current->value == value)
            return current;
        current = current->next;
    }

    return NULL;
}

struct ListNode* createList(int array[], int size) {
    struct ListNode* head = createNode(array[0]);

    int i = 1;
    while(i < size) {
        append(head, array[i]);
        ++i;
    }

    return head;
}

int main() {
    int array1[3] = {1, 3, 6};
    struct ListNode* list1 = createList(array1, 3);

    insert(list1, list1->next, 2);
    prepend(list1, 1);
    append(list1, 9);

    printList(list1);

    return 0;
}

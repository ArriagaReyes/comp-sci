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

/*struct ListNode* mergeSort(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* cursor1;
    struct ListNode* cursor2;
    struct ListNode* node;

    while(cursor1 && cursor2) {
        if(cursor->value < cursor2->value) {
            node = createNode(cursor->value);
        }

        cursor1 = cursor1->next;
        cursor2 = cursor2->next;
    }
}*/

struct ListNode* insertionSort(int array[], int size) {
    struct ListNode* head = createNode(array[0]);
    struct ListNode* current;
    struct ListNode* next;
    struct ListNode* temp;

    for(int i = 1; i < size; i++) {
        current = head;
        while(current != NULL) {
            if(current->next != NULL) {
                if(array[i] > current->value && array[i] <= current->next->value) {
                    insert(current, current->next, array[i]);
                    current = NULL;
                } else if(array[i] < current->value) {
                    struct ListNode* node = createNode(array[i]);

                    node->next = head;
                    head = node;

                    current = NULL;
                } else {
                    current = current->next;
                }
            } else {
                insert(current, current->next, array[i]);
                current = NULL;
            }
        }
    }

    return head;
}

int main() {
    int array1[6] = {9, 8, 7, 6, 5, 4};
    struct ListNode* list = insertionSort(array1, 6);

    //struct ListNode* list = createNode(4);
    //list = prepend(list, 1);

    printList(list);

    return 0;
}

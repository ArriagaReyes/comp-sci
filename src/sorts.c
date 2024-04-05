#include "../include/sorts.h"
#include "../include/LinkedList.h"
#include <stdlib.h>
#include <stdio.h>

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

void merge(int* leftArray, int* rightArray, struct Array** parent) {
    struct Array* temp = (*parent);
    int leftLength = temp->length / 2;
    int rightLength = temp->length - leftLength;

    int i = 0, left = 0, right = 0;
    while(left < leftLength && right < rightLength) {
        if(leftArray[left] < rightArray[right]) {
            (*parent)->list[i] = leftArray[left];
            ++left; ++i;
        } else {
            (*parent)->list[i] = rightArray[right];
            ++right; ++i;
        }
    }

    while(left < leftLength) {
        (*parent)->list[i] = leftArray[left];
        ++left; ++i;
    }

    while(right < rightLength) {
        (*parent)->list[i] = rightArray[right];
        ++right; ++i;
    }
}

void mergeSort(struct Array** parent) {
    if((*parent)->length <= 1) return;

    struct Array* temp = (*parent);
    int length = temp->length;
    int middle = length / 2;

    struct Array* leftChild = (struct Array*) malloc(sizeof(struct Array));
    leftChild->length = middle;
    leftChild->list = (int*) malloc(middle * sizeof(int));

    struct Array* rightChild = (struct Array*) malloc(sizeof(struct Array));
    rightChild->length = length - middle;
    rightChild->list = (int*) malloc((length - middle) * sizeof(int));

    for(int left = 0, right = 0, i = 0; i < temp->length; i++) {
        if(i < middle) {
            leftChild->list[left] = temp->list[i];
            ++left;
        } else {
            rightChild->list[right] = temp->list[i];
            ++right;
        }
    }

    mergeSort(&leftChild);
    mergeSort(&rightChild);
    merge(leftChild->list, rightChild->list, parent);

    free(leftChild->list);
    free(leftChild);
    free(rightChild->list);
    free(rightChild);
}

struct LinkedList* mergeLists(struct LinkedList* list1, struct LinkedList* list2) {
    struct ListNode* item1;
    struct ListNode* item2;

    if(empty(list1) || empty(list2)) return NULL;

    struct LinkedList* output = createList(NULL, 0);

    item1 = dequeue(list1);
    item2 = dequeue(list2);

    while(item1 && item2) {
        if(item1->value < item2->value) {
            append(output, item1->value);
            free(item1);
            item1 = dequeue(list1);
        } else {
            append(output, item2->value);
            free(item2);
            item2 = dequeue(list2);
        }
    }

    while(item1) {
        append(output, item1->value);
        free(item1);
        item1 = dequeue(list1);
    }

    while(item2) {
        append(output, item2->value);
        free(item2);
        item2 = dequeue(list2);
    }

    return output;
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


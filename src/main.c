#include <stdio.h>
#include <stdlib.h>
#include "../include/LinkedList.h"
#include "../include/Queue.h"

struct Array {
    int* list;
    int length;
};

void printArray(struct Array* items) {
    printf("Printing array of size %d\n", items->length);
    for(int i = 0; i < items->length; i++)
        printf("list[%d]: %d\n", i, items->list[i]);
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

void freeList(struct LinkedList** listptr) {
    struct LinkedList* list = (*listptr);
    if(!list) return;
    if(!list->head) return;
    struct ListNode* current = dequeue(list);

    while(current) {
        current->next = NULL;
        free(current);
        current = dequeue(list);
    }

    (*listptr)->head = NULL;
    (*listptr) = NULL;

    free((*listptr));
}

int main() {
    int array1[9] = {1, 2, 3, 3, 4, 5, 7, 7, 9};
    int array2[6] = {2, 4, 4, 6, 7, 10};

    struct LinkedList* list1 = createList(array1, 9);
    struct LinkedList* list2 = createList(array2, 6);

    struct LinkedList* list = mergeLists(list1, list2);

    printList(list);

    freeList(&list1);
    freeList(&list2);
    freeList(&list);

    return 0;
}

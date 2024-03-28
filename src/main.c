#include <stdio.h>
#include <stdlib.h>

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

int main() {
    struct Array* items = (struct Array*) malloc(sizeof(struct Array));
    items->length = 8;
    items->list = (int*) malloc(items->length * sizeof(int));

    int list[8] = {9, 8, 7, 6, 5, 4, 3, 2};

    for(int i = 0; i < items->length; i++)
        items->list[i] = list[i];

    printArray(items);
    mergeSort(&items);
    printArray(items);

    free(items->list);
    free(items);

    return 0;
}

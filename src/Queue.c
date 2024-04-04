#include "../include/Queue.h"

void queue_Enqueue(LinkedList* list, void* value) {
    linkedList_Append(list, value);
}

void* queue_Dequeue(LinkedList* list) {
    return linkedList_Snap(list);
}

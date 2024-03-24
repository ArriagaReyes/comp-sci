#Heap sort

Selection sort where I is a heap.

Start with empty list S and unsorted list I
of n items.

Toss all items in I onto a heap h (ignoring
heap-order)
h.bottomUpHeap(); <- O(n) time
for(i = 0; o < n; i++) {
    x = h.removeMin(); <- O(log n) time
    Append x to the end of S
}

Heapsort runs in O(n log n) time.
It can also be done in-place. It is also
really good at sorting arrays, but doesn't
do so hot with linked lists.

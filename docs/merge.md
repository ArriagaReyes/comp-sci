#Merge sort

Merge sort is better for linked lists and
less for arrays.

Merge 2 sorted lists into one sorted list
in linear time O(n).

Let Q1 and Q2 be two sorted queus.
Let Q be empty queue.
while(neither Q1 nor Q2 is empty) {
    item1 = Q1.front().
    itme2 = Q2.front().

    move smaller of item1, item2 from
    present queue to end of Q.
}
concatinate remaing non-empty queue
(Q1 or Q2) to the end of Q.

Merge sort is a reursive divide-and-
conquer algorithm.

Start with list I of n items
Break I into halves I1 and I2
Sort I1 recursively, yeilding S1
Sort I2 recursively, yeilding S2
merge S1 and S2 into one sorted list S

Merge sort runs at O(n log n) time

This kind of sort is natural for linked lists
but it's not in-place sort for arrays.

#Selection sort

Selection sort runs at O(n^2) time.

Start with empty list S and unsorted list I
of n items
for(i = 0; i < n; i++) {
    x <- item in I with the smallest key
    Remove x from I
    Appended x to end of S
}

Whether S is array or linked list selection
sort takes theta(n^2) time even in the best case,
but it can be done in-place.

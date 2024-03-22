#Insertion Sort

Insertion sort runs at O(n^2) time.

Start with empty list S and unsorted list I of n items.
for (each item x in I) {
    insert x into S, in sorted order
}

If S is a linked list, theta(n) worst-case time to find right
position.

If S is an array, theta(n) worst case time to shift higher
items over.

If S is an array, insertion sort is in-place.
In-place is where you use little memory to sort items all within an array.

I = [7, 3, 9, 5] => [7, 3, 9, 5 ] => [3, 7, 9, 5] => [3, 7, 9, 5]
                     S  I                S  I               S  I
=> [3, 5, 7, 9]
             S
If S is a balanced search tree, running time O(nlog n).
Insertion sort for balanced trees is impractial.

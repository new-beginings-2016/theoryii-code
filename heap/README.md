Basic Heap Implementation

This version of a heap, taken from K&T's Algorithm Design implements a priority queue with the following operations:

    - StartHeap(N) returns an empty heap H that is set up to store at most N elements. This operation takes O(N) time, as it involves initializing the array that will hold the heap.

    - Insert(H, v) inserts the item v into heap H. If the heap currently has n elements, this takes O(log n) time.

    - FindMin(H) identifies the minimum element in the heap H but does not remove it. This takes O(1) time.

    - Delete(H, i) deletes the element in heap position i. This is implemented in O(log n) time for heaps that have n elements.

    - ExtractMin(H) identfies and deletes an element with miminum key value from a heap. Takes O(log n) time. 

    - ChangeKey(H, v, alpha) changes the key value of element v to key(v) = alpha. Also takes O(log n) time.

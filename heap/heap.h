#include "bool.h"

#ifndef __HEAP_H__
#define __HEAP_H__

#define MAX_SIZE 1024
#define ROOT_INDEX 1

struct heap_t;
struct node_t;

struct heap_t {
    int size;
    struct node_t **queue;
};

struct node_t {
    int data;
    int key;
};

/* 
   StartHeap(N):
   
   Returns an empty heap H that is set up to store at most <size:int> elements. This
   operation takes O(N) time, as it involves initializing the array that will hold
   the heap.
*/
struct heap_t * start_heap(int capacity);

/*
    Insert(H, v):

    Inserts the item <v:struct node_t> into heap <H:heap_t>. If the heap currently has
    n elements, this takes O(log n) time.

    Returns TRUE if item was successfully inserted. Returns FALSE otherwise.
*/
int insert(struct heap_t *, struct node_t *);

/*
   FindMin(H):

   Identifies the minimum element in the heap <H:heap_t> but does not remove it. This
   takes O(1) time.
*/
struct node_t * find_min(struct heap_t *);

/*
    Delete(H, i):

    Deletes the element in heap position <i: int>. This is implemented in O(log n)
    time for heaps that have n elements.
*/
void remove_node(struct heap_t *, const int i);

/*
   ExtractMin(H):

   Identifies and deletes an element with minimum key value from a heap. This is a
   combination of the preceding two operations and so it takes O(log n) time.
*/
struct node_t * extract_min(struct heap_t *);

/*
   RemoveHeap(H):

   Frees memory of every element in the heap, and then the heap itself.
*/
void remove_heap(struct heap_t **);
#endif

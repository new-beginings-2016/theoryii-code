#include "heap.h"

#include <stdlib.h>
#include <stdio.h>

struct heap_t * start_heap(int capacity)
{
    struct heap_t *H;
    int i;

    if (capacity <= MAX_SIZE) {
	H = malloc(sizeof(struct heap_t));
	H->size = 0;

	H->queue = malloc(sizeof(struct node_t *) * (ROOT_INDEX + capacity));
	for (i = 1; i <= capacity; i++) {
	    H->queue[i] = 0;
	}

	return H;
    } else {
	return 0;
    }
}

void swap(struct node_t ** arr, int i, int j)
{
    struct node_t *tmp;

    tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

void heapify_up(struct heap_t *H, const int i)
{
    int current, parent;
    struct node_t ** Q = H->queue;

    if (i > 1) {
	current = i;
	parent = current / 2;
	if (Q[current]->key < Q[parent]->key) {
	    swap(Q, current, parent);
	    heapify_up(H, parent);
	}
    }
}


int insert(struct heap_t *H, struct node_t *v)
{
    if (H->size < MAX_SIZE) {
	H->queue[++(H->size)] = v;
	heapify_up(H, H->size);

	return SUCCESS;
    } else {
	return FAILURE;
    }
}

struct node_t *find_min(struct heap_t *H)
{
    return H->queue[ROOT_INDEX];
}

void heapify_down(struct heap_t * H, const int i)
{
    int current, child, size, lchild, rchild;
    struct node_t ** Q = H->queue;

    size = H->size;

    if (i * 2 > size) { /* current has no children */
	return;
    } else if (i * 2 < size) {
	current = i;
	lchild = 2 * current, rchild = 2 * current + 1;
	if (Q[lchild]->key <= Q[rchild]->key) {
	    child = lchild;
	} else {
	    child = rchild;
	}
    } else {
	current = i;
	child = 2 * current;
    }

    if (Q[child]->key < Q[current]->key) {
	swap(Q, current, child);

	heapify_down(H, child);
    }
}

void remove_node(struct heap_t *H, const int i)
{
    if (H->size < ROOT_INDEX) {
	fprintf(stderr, "Warning: No elements in heap left to remove.");
    } else {
	H->queue[i] = H->queue[H->size];
	H->queue[H->size--] = 0;
	heapify_down(H, i);
    }
}

struct node_t * extract_min(struct heap_t *H)
{
    struct node_t *min = H->queue[ROOT_INDEX];

    remove_node(H, ROOT_INDEX);

    return min;
}

void remove_heap(struct heap_t ** H)
{
    struct heap_t *heap;
    int i, size;

    heap = *H;
    size = heap->size;

    for (i = 1; i <= size; i++) {
	free(heap->queue[i]);
	heap->queue[i] = 0;
    }

    free(heap);
    heap = 0;
}

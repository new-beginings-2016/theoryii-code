/*
   program demonstrating how to use a heap.
*/
#include "heap.h"

#include <stdlib.h>
#include <stdio.h>

#define HEAP_SIZE 10

struct node_t * make_node(int id, int key)
{
    struct node_t * v;

    v = malloc(sizeof(struct node_t));

    v->data = id;
    v->key = key;

    return v;
}

int main(int argc, char *argsv[])
{
    struct heap_t *pqueue;
    int vertex_name, key, i;
    struct node_t * tmp;
    
    pqueue = start_heap(HEAP_SIZE);

    for (i = 0; i < HEAP_SIZE; i++)
    {
	vertex_name = i;
	key = rand() % 100;

	insert(pqueue, make_node(vertex_name, key));
    }

    for (i = 0; i < HEAP_SIZE; i++)
    {
	tmp = extract_min(pqueue);
	printf("%d - weight %d\n", tmp->data, tmp->key);
	tmp = 0;
    }	

    remove_heap(&pqueue);

    return 0;
}

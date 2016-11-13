#include "llist.h"
#include "adjacency_list.h"

#include <stdlib.h>

void make_adjacency_list(struct adjlist_t **graph)
{
    *graph = malloc(sizeof(struct adjlist_t));
}

void free_adjacency_list(struct adjlist_t *graph)
{
    int i, size;

    size = graph->vertexcount;
    for (i = 0; i < size; i++) {
	free_list(graph->vertices[i]);
	graph->vertices[i] = 0;
    }

    free(graph);
}

void read_adjacency_list(struct adjlist_t *graph, FILE *fp)
{
    int i, size, v1, v2;

    fscanf(fp, "%s ", graph->name);
    fscanf(fp, "%d ", &(graph->vertexcount));
    fscanf(fp, "%d ", &(graph->size));
    
    size = graph->size;
    for (i = 0; i < size; i++) {
	fscanf(fp, "%d %d ", &v1, &v2);
	add_to_list(graph->vertices[v1], v2);
    }
}


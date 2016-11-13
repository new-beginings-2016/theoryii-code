#include "llist.h"
#include "adjacency_list.h"

#include <stdlib.h>
#include <string.h>

void make_adjacency_list(struct adjlist_t **graph)
{
    int i;

    *graph = malloc(sizeof(struct adjlist_t));

    for (i = 0; i < MAX_VERTEX_COUNT; i++) {
	make_list(&((*graph)->vertices[i]));
    }
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
    char buff[MAX_NAME_LENGTH];

    fgets(buff, MAX_NAME_LENGTH, fp);
    strcpy(graph->name, buff);

    fgets(buff, 3, fp);
    graph->vertexcount = atoi(buff);

    fgets(buff, 3, fp);
    graph->size = atoi(buff);

    size = graph->size;
    for (i = 0; i < size; i++) {
	fgets(buff, 10, fp);
	v1 = atoi(strtok(buff, " "));
	v2 = atoi(strtok(0, " "));

	add_to_list(graph->vertices[v1-1], v2); 
    }
}

#define MAX_NAME_LENGTH 20
#define MAX_VERTEX_COUNT 20

#include <stdio.h>

struct llist_t;

struct adjlist_t {
    struct llist_t *vertices[MAX_VERTEX_COUNT]; 
    char name[MAX_NAME_LENGTH];
    int size;
    int vertexcount;
};

void make_adjacency_list(struct adjlist_t **graph);

void free_adjacency_list(struct adjlist_t *graph);

/** 
  Line 1: <graph_name>
  Line 2: v (no. of vertices)
  Line 3: e (no. of edges)
  Line 4: e+4 (v1, v2) edge pairs
*/
void read_adjacency_list(struct adjlist_t *graph, FILE *fp);

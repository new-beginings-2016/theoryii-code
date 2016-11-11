/*
    This program reads in a list of edges (v1, v2) and outputs 
    an equivalent adjacency matrix to stdout.

    Assume the graph is directed. This means when writing input files, 
    one must specify edges in both directions when graph is undirected.

    New Beginnings, Theory II Code Repo
*/

#define SIZE 10
#define SPARSENESS_THRESHOLD .75
#define MAX_NAME_LENGTH 20

#include <stdio.h>

struct adjmat_t {
    char name[MAX_NAME_LENGTH];
    int matrix[SIZE][SIZE];
    int size;
};

/** Initialize and populate adjacency matrix. */
void make_adjacency_matrix(struct adjmat_t **, int size);

/** Sets a matrix cell to 1 to signify an edge. */
void mset(struct adjmat_t *graph, int row, int column);

/** Prints matrix to stdout. */
void show_adjacency_matrix(struct adjmat_t *);

/** Reads an adjacency matrix from a file 
  Line 1: <graph_name>
  Line 2: v (no. of vertices)
  Line 3: e (no. of edges)
  Line 4...e+4: (v1,v2) edge pairs
*/
void read_adjacency_matrix(struct adjmat_t *, FILE *fp);

/** Determines whether or not a graph is sparse. */
int issparse(struct adjmat_t *);

/** Determines if two graphs are identical */
int issame(struct adjmat_t *, struct adjmat_t *);

/** Computes the transitive closure of a graph */
void transitive_closure(struct adjmat_t *tc, struct adjmat_t *graph);

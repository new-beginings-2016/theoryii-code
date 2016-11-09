/*
    This program reads in a list of edges (v1, v2) and outputs 
    an equivalent adjacency matrix to stdout.

    New Beginnings, Theory II Code Repo
*/

#define SIZE 10
#define SPARSENESS_THRESHOLD .75

#include <stdio.h>

struct adjmat_t {
    int matrix[SIZE][SIZE];
    int size;
};

/** Initialize and populate adjacency matrix. */
void make_adjacency_matrix(struct adjmat_t **, int size);

/** Sets a matrix cell to 1 to signify an edge. */
void mset(struct adjmat_t *graph, int row, int column);

/** Prints matrix to stdout. */
void show_adjacency_matrix(struct adjmat_t *);

/** Reads an adjacency matrix from a file */
void read_adjacency_matrix(struct adjmat_t *, FILE *fp);

/** Determines whether or not a graph is sparse. */
int issparse(struct adjmat_t *);

/** Determines if two graphs are identical */
int issame(struct adjmat_t *, struct adjmat_t *);

/** Computes the transitive closure of a graph */
void transitive_closure(struct adjmat_t *tc, struct adjmat_t *graph);

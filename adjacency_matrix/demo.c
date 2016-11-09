/**
    Example on how to use the adjacency matrix data type.
*/

#include "adjacency_matrix.h"

#include <stdio.h>

int main(int argc, char *argsv[])
{
    FILE *fp = fopen("input.txt", "r");
    struct adjmat_t *graph;

    read_adjacency_matrix(&graph, fp);
    show_adjacency_matrix(graph);

    if (issparse(graph)) {
        puts("The graph is sparse.");
    }

    return 0;
}

/**
    Example on how to use the adjacency matrix data type.
*/

#include "adjacency_matrix.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argsv[])
{
    FILE *fp = fopen("input.txt", "r");
    struct adjmat_t *graph;

    make_adjacency_matrix(&graph, 0);

    read_adjacency_matrix(graph, fp);
    show_adjacency_matrix(graph);

    if (issparse(graph)) {
        puts("The graph is sparse.");
    }

    fclose(fp);
    free(graph);
    return 0;
}

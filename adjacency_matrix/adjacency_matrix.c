#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <assert.h>

#include "adjacency_matrix.h"

#define SQUARE(x) x*x

void make_adjacency_matrix(struct adjmat_t ** graph, int size)
{
    int i, j;

    assert(size <= SIZE);
    *graph = malloc(sizeof(struct adjmat_t));

    (*graph)->size = size;

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            (*graph)->matrix[i][j] = 0;
        }
    }
}

void show_adjacency_matrix(struct adjmat_t * graph)
{
    int size, i, j;

    puts(graph->name);

    size = graph->size;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("%d ", graph->matrix[i][j]);
        }
        puts("");
    }
}

int get_num(FILE *fp)
{
    int number = 0;
    char ch;

    while (isspace(ch = fgetc(fp)));

    fseek(fp, ftell(fp) - 1, 0L);
    while (EOF != (ch = fgetc(fp)) && !isspace(ch))
    {
        number *= 10;
        number += ch - '0';
    }

    return number;
}

void read_adjacency_matrix(struct adjmat_t *graph, FILE *fp)
{
    int size, i, edges, v1, v2;

    fgets(graph->name, MAX_NAME_LENGTH, fp);

    size = get_num(fp); /* read the number of vertices */
    graph->size = size;

    edges = get_num(fp);

    for (i = 0; i < edges; i++) {
	v1 = get_num(fp) - 1; v2 = get_num(fp) - 1; /* vertices are labeled 1...N */
	graph->matrix[v1][v2] = 1; 
    }
}

int issparse(struct adjmat_t *graph)
{
    int i, j, zerocount, totalcount;

    zerocount = 0;
    for (i = 0; i < graph->size; i++) {
        for (j = i; j < graph->size; j++) { 
            if (!graph->matrix[i][j] && !graph->matrix[j][i]) {
                zerocount++;
            }
        }
    }

    zerocount *= 2;
    totalcount = SQUARE(graph->size); 

    return ((float) zerocount / totalcount) >= SPARSENESS_THRESHOLD;
}

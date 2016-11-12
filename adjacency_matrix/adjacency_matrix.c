#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <assert.h>

#include "adjacency_matrix.h"

#define SQUARE(x) x*x

void make_adjacency_matrix(struct adjmat_t ** graph)
{
    int i, j;

    *graph = malloc(sizeof(struct adjmat_t));

    for (i = 0; i < VERTICES; i++) {
        for (j = 0; j < VERTICES; j++) {
            (*graph)->matrix[i][j] = 0;
        }
    }
}

void show_adjacency_matrix(struct adjmat_t * graph)
{
    int vertices, i, j;

    puts(graph->name);

    vertices = graph->vertices;
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
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
    int vertices, i, size, v1, v2;

    fgets(graph->name, MAX_NAME_LENGTH, fp);

    vertices = get_num(fp); /* read the number of vertices */
    graph->vertices = vertices;

    size = get_num(fp);

    for (i = 0; i < size; i++) {
	v1 = get_num(fp) - 1; v2 = get_num(fp) - 1; /* vertices are labeled 1...N */
	graph->matrix[v1][v2] = 1; 
    }
}

int issparse(struct adjmat_t *graph)
{
    int i, j, zerocount, totalcount;

    zerocount = 0;
    for (i = 0; i < graph->vertices; i++) {
        for (j = i; j < graph->vertices; j++) { 
            if (!graph->matrix[i][j] && !graph->matrix[j][i]) {
                zerocount++;
            }
        }
    }

    zerocount *= 2;
    totalcount = SQUARE(graph->vertices); 

    return ((float) zerocount / totalcount) >= SPARSENESS_THRESHOLD;
}

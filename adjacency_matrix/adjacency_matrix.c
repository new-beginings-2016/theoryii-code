#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <assert.h>

#include "adjacency_matrix.h"

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

void mset(struct adjmat_t *graph, int row, int column)
{
    graph->matrix[row][column] = graph->matrix[column][row] = 1;
}

void show_adjacency_matrix(struct adjmat_t * graph)
{
    int size, i, j;

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
    int size, i, j;
    long file_size;

    fseek(fp, 0L, SEEK_END);
    file_size = ftell(fp);
    fseek(fp, 0L, SEEK_SET);

    size = get_num(fp);
    graph->size = size;

    while(ftell(fp) != file_size) {
        i = get_num(fp); j = get_num(fp);
        mset(graph, i - 1, j - 1);
    }
}

int issparse(struct adjmat_t *graph)
{
    int i, j, zerocount, totalcount;

    zerocount = 0;
    for (i = 0; i < graph->size; i++) {
        for (j = 0; j < graph->size; j++) {
            if (!graph->matrix[i][j]) {
                zerocount++;
            }
        }
    }
    totalcount = graph->size * graph->size;

    return ((float) zerocount / totalcount) >= SPARSENESS_THRESHOLD;
}

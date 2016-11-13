#include "adjacency_list.h"

#include <stdio.h>

#define MAX_FILENAME_LENGTH 20

void prompt_for_filename(char *filename)
{
    puts("Where is the input file?");
    scanf("%s", filename);
}

int main(int argc, char *argsv[])
{
    struct adjlist_t * graph;
    char filename[MAX_FILENAME_LENGTH];
    FILE *fp;

    prompt_for_filename(filename);
    fp = fopen(filename, "r");

    make_adjacency_list(&graph);
    read_adjacency_list(graph, fp);

    free_adjacency_list(graph);
    fclose(fp);
    return 0;
}

#include "dfa.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argsv[])
{
    struct dfa_t *dfa;
    FILE *fp;
    int input[5] = { 0, 1, 1, 1, 1 };

    fp = fopen("dfa.txt", "r");

    make_dfa(&dfa);
    read_dfa(dfa, fp);

    if (accepts_input(dfa, input, 5)) {
        puts("divisible by 3");
    } else {
        puts("not divisible by 3");
    }

    fclose(fp);
    free(dfa);
    return 0;
}

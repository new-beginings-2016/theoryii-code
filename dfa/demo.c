#include "dfa.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argsv[])
{
    struct dfa_t *dfa;
    FILE *fp;

    fp = fopen("m1.dfa", "r");

    make_dfa(&dfa);
    read_dfa(dfa, fp);

    print_dfa(dfa);

    fclose(fp);
    free(dfa);
    return 0;
}

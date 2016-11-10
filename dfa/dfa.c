#include "dfa.h"

#include <ctype.h>
#include <stdlib.h>

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

void make_dfa(struct dfa_t **dfa) {
    int i, j;
    *dfa = malloc(sizeof(struct dfa_t));

    for (i = 0; i < MAX_STATES; i++) {
        (*dfa)->accept_states[i] = 0;
        for (j = 0; j < MAX_LETTERS; j++) {
            (*dfa)->transition_table[i][j] = 0;
        }
    }
}

void read_dfa(struct dfa_t * dfa, FILE *fp)
{
    int i, j;

    dfa->states = get_num(fp);
    dfa->letters = get_num(fp);

    for (i = 0; i < dfa->states; i++)
    {
        for (j = 0; j < dfa->letters; j++) {
            dfa->transition_table[i][j] = get_num(fp);
        }
    }

    dfa->start_state = get_num(fp);
    dfa->accept_state_count = get_num(fp);

    for (i = 0; i < dfa->accept_state_count; i++) {
        dfa->accept_states[i] = get_num(fp);
    }
}

int accepts_input(struct dfa_t * dfa, int *input, int len)
{
    int i, state;

    state = dfa->start_state;
    for (i = 0; i < len; i++) {
        state = dfa->transition_table[state][input[i]];
    }

    for (i = 0; i < dfa->accept_state_count; i++) {
        if (dfa->accept_states[i] == state) {
            return SUCCESS;
        }
    }

    return FAILURE;
}

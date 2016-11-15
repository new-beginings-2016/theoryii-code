/*
    New Beginnings, Theory II Code Base

    This file contains code for a deterministic finite automaton states 0,...,N - 1;
    with an alphabet of {0, ..., M - 1}; a state transition table; a given start state; and
    a given set of final states.
*/

#include <stdio.h>

#include "bool.h"

#define MAX_STATES 16
#define MAX_LETTERS 16
#define MAX_NAME_LENGTH 80
#define MAX_LINE_LENGTH 80

struct dfa_t {
    int transition_table[MAX_STATES + 1][MAX_LETTERS];
    char *name;
    char *alphabet;
    int *accept;
    int start_state;
    int num_states;
    int accept_states;
    int alphabet_size;
};


/*
    Input Format:
    Line 1: Name
    Line 2: Alphabet: <characters array>
    Line 3: States: <# states>
    Line 4: Start State: <character>
    Line 5: Accept States: <int array>
    Line 6 - alphabet: Transition Function
    _ a b ...
    s1 delta(state, input)
    s2 
    ...
*/
void read_dfa(struct dfa_t * dfa, FILE *fp);

/* constructs a dfa based on definition */
void make_dfa(struct dfa_t **dfa);

/* computes whether or not a string is accepted by a dfa */
int accepts_input(struct dfa_t * dfa, int *input, int len);

void print_dfa(struct dfa_t *dfa);

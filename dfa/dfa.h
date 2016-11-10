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

struct dfa_t {
    int states; // number of states 0, 1,...,N-1
    int letters; // number of symbols 0, 1,...,M-1
    int transition_table[MAX_STATES][MAX_LETTERS];
    int start_state;
    int accept_states[MAX_STATES];
    int accept_state_count;
};


/*
    Input Format:
        Line 1: N
        Line 2: M
        Line 3...N-2: f(k,0) f(k,1) ... f(k,M-1) ; 0 <= k <= N-1
        Line 4: s
        Line 5: L
        Line 5: f_0, f_1, ... , f_L
*/
void read_dfa(struct dfa_t * dfa, FILE *fp);

/* constructs a dfa based on definition */
void make_dfa(struct dfa_t **dfa);

/* computes whether or not a string is accepted by a dfa */
int accepts_input(struct dfa_t * dfa, int *input, int len);

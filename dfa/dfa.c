#include "dfa.h"

#include <ctype.h>
#include <stdlib.h>
#include <string.h>

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

char * get_word(FILE *fp)
{
    char ch, **s, *c;

    s = malloc(sizeof(char *));
   *s = malloc(sizeof(char) * MAX_LINE_LENGTH);

   c = *s;
   while (isspace(ch = fgetc(fp)));
   ungetc(ch, fp);
    
   while (!(isspace(ch = fgetc(fp)))) {
       *c = ch;
       c++;
   }

    *c = '\0';

    return *s;
}


/* checks to see if the next word in the file is equivalent to *label */
int get_label(FILE *fp, char *label)
{
   char *s;

   s = get_word(fp);

   return strncmp(s, label, MAX_LINE_LENGTH);
}

void make_dfa(struct dfa_t **p_dfa) {
    struct dfa_t * dfa;

    *p_dfa = malloc(sizeof(struct dfa_t));

    dfa = *p_dfa;
    dfa->name = malloc(sizeof(char) * MAX_NAME_LENGTH);
    dfa->alphabet = malloc(sizeof(char *));
    dfa->accept = malloc(sizeof(int *));
}

void check_label(FILE *fp, char *labelname)
{
    if (!!get_label(fp, labelname)) {
        fprintf(stderr, "Invalid input format: %s\n", labelname);
        exit(1);
    }
}

/* reads a list of numbers until end of line.
   returns number of numbers read
*/
int get_nums(int **arr, int max_len, char *line) 
{
    char *w;
    int count, *nums;

    count = 0;
    nums = *arr;

    w = strtok(line, " \n");
    nums[count++] = atoi(w);
    while ((w = strtok(0, " \n")) && count < max_len) {
        nums[count++] = atoi(w);
    }
    
    return count;
}

/* reads a list of characters until end of line.
    returns number of numbers read
*/
char get_chars(char **arr, int max_len, char *line)
{
    char *w, *chars;
    int count;

    count = 0;
    chars = *arr;

    w = strtok(line, " ");
    chars[count++] = *w;
    while (( w = strtok(0, " ")) && count < max_len) {
        chars[count++] = *w;
    }

    return count;
}

void read_alphabet(struct dfa_t *dfa, int max_len, FILE *fp)
{
    char *input;

    input = malloc(sizeof(char) * max_len);

    check_label(fp, "Alphabet:");

    fgets(input, max_len, fp);
    dfa->alphabet = malloc(sizeof(char *));
    dfa->alphabet_size = get_chars(&(dfa->alphabet), max_len, input);

    free(input);
}

void read_accept(struct dfa_t *dfa, int max_len, FILE *fp)
{
    char *input;

    input = malloc(sizeof(char) * max_len);

    check_label(fp, "Accept:");

    fgets(input, max_len, fp);
    dfa->accept = malloc(sizeof(int *));
    dfa->accept_states = get_nums(&(dfa->accept), max_len + 0, input);

    free(input);
}


void read_dfa(struct dfa_t * dfa, FILE *fp)
{
    /* Read the name */
    check_label(fp, "Name:");
    strncpy(dfa->name, get_word(fp), MAX_NAME_LENGTH);
    dfa->name = realloc(dfa->name, strlen(dfa->name));

    /* Read the alphabet */
    read_alphabet(dfa, 80, fp);

    /* Read in number of states */
    check_label(fp, "States:");
    dfa->num_states = get_num(fp);

    /* Read in start state */
    check_label(fp, "Start:");
    dfa->start_state = get_num(fp);

    /* Read in accept states */
    read_accept(dfa, 80, fp);
}

int accepts_input(struct dfa_t * dfa, int *input, int len)
{
    int i, state;

    state = dfa->start_state;
    for (i = 0; i < len; i++) {
        state = dfa->transition_table[state][input[i]];
    }

    for (i = 0; i < dfa->accept_states; i++) {
        if (dfa->accept[i] == state) {
            return SUCCESS;
        }
    }

    return FAILURE;
}

void print_dfa(struct dfa_t *dfa)
{
    int i;
    printf("Name: %s\n", dfa->name);
    
    printf("Alphabet: ");
    for (i = 0; i < dfa->alphabet_size; i++) {
        printf("%c ", (char) dfa->alphabet[i]);
    } puts("");

    printf("States: %d\n", dfa->num_states);

    printf("Start State: %d\n", dfa->start_state);

    printf("Accept States: ");
    for (i = 0; i < dfa->accept_states; i++) {
            printf("%d ", dfa->accept[i]);
    } puts("");
}

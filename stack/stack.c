//stack.c
// Bryant W. York
// November 2016

#include <stdlib.h>
#include "stack.h"
#include "../bool.h"

void initialize_stack(struct stack_t **stack)
{
    struct llist_t **l;

    *stack = malloc(sizeof(struct stack_t));
    l = &((*stack)->list);

    make_list(l);

    (*stack)->size = 0;
}

void push(struct stack_t *stack, int data)
{
    add_first(stack->list, data);   
    stack->size++;
}

int pop(struct stack_t *stack)
{
    int data;
    struct node_t *t;
   
    data = stack->list->head->data;
    t = stack->list->head;

    stack->list->head = stack->list->head->next;

    free(t); t = 0;
    stack->size--;

    return data;
}

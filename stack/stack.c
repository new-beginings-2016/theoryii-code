//stack.c
// Bryant W. York
// November 2016

#include <stdlib.h>
#include "stack.h"
#include "../bool.h"

void initialize_stack(struct stack_t *stack)
{
    stack->head = 0;
    stack->size = 0;
}

int push(struct stack_t *stack, struct node_t *node)
{
    if (!stack->head)
    {
        stack->head = node;
        stack->size++;
        stack->head->next = 0;
    }
    else
    {
        node->next = stack->head;
        stack->head = node;

        stack->size++;
    }

    return SUCCESS;
}

struct node_t * pop(struct stack_t *stack)
{
    struct node_t *r;

    if (!stack->head) {
        return 0;
    }

    r = stack->head;
    stack->head = stack->head->next;
    stack->size--;

    return r;
}

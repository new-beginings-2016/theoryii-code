#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "stack.h"

int main(int argc, char *argsv[])
{
    int i, d, t;
    struct stack_t * stack;

    initialize_stack(&stack);

    for (i = 1; i < argc; i++) {
	d = atoi(argsv[i]);
	push(stack, d);
    }

    while (stack->size) {
        t = pop(stack);

        printf("%d ", t);
    } 
    puts("");

    free_stack(stack);

    return 0;
}

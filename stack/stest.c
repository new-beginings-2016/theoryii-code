#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "stack.h"

int main(void)
{
    struct node_t node1, node2, node3, *t;
    struct stack_t stack;

    node1.data = 1;
    node1.next = &node2;

    node2.data = 2;
    node2.next = &node3;

    node3.data = 3;
    node3.next = 0;

    initialize_stack(&stack);
    push(&stack, &node1);
    push(&stack, &node2);
    push(&stack, &node3);


    /* Should print 3 2 1 */
    while (stack.size) {
        t = pop(&stack);

        printf("%d ", t->data);
    } 
    puts("");

    /* tests pop on null */
    assert (!pop(&stack));
    return 0;
}

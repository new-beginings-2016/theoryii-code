//stack.h
// Bryant W. York
// November 2016

struct llist_t;

struct stack_t {
    struct llist_t *list;
    int size;
};

void initialize_stack(struct stack_t **);
void push(struct stack_t *, int);
int pop(struct stack_t *);

//stack.h
// Bryant W. York
// November 2016

struct node_t
{
  int data;
  struct node_t* next;
};

struct stack_t {
    struct node_t *head;
    int size;
};


void initialize_stack(struct stack_t *);
int push(struct stack_t *, struct node_t *);
struct node_t * pop(struct stack_t *);

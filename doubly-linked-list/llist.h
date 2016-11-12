/*
   Basic code for a doubly linked list.

   New Beginnings/Theory II
*/

struct node_t {
    int data;
    struct node_t *prev;
    struct node_t *next;
};

struct llist_t {
    struct node_t *head;
    struct node_t *tail;
};

void make_node(struct node_t **node, int data, struct node_t *prev, struct node_t *next);

void make_list(struct llist_t **list);

void add(struct llist_t *list, int data);


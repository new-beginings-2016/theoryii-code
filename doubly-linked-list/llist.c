#include "llist.h"

#include <stdlib.h>
#include <stdio.h>

void make_node(struct node_t **node, int data, struct node_t *prev, struct node_t *next)
{
    *node = malloc(sizeof(struct node_t));

    (*node)->data = data;

    (*node)->prev = prev;
    (*node)->next = next;
}


void make_list(struct llist_t **list)
{
    *list = malloc(sizeof(struct llist_t));

    (*list)->head = 0;
    (*list)->tail = (*list)->head;
}

void add_to_list(struct llist_t *list, int data)
{
    struct node_t *new_node;

    make_node(&new_node, data, 0, 0);
    if (!list->head)
    {
	list->head = new_node;

	list->tail = list->head;
    } else {
	new_node->prev = list->tail;

	list->tail->next = new_node;
	list->tail = new_node;
    }
}

void add_first(struct llist_t *list, int data)
{
    struct node_t *new_node;

    make_node(&new_node, data, 0, 0);
    if (!list->head)
    {
	list->head = new_node;
	list->tail = list->head;
    } else {
	new_node->next = list->head;
	list->head->prev = new_node;

	list->head = new_node;
    }
}

void print_list(struct llist_t *list)
{
    struct node_t *p;

    if ((p = list->head)) {

	while (p) {
	    printf("%d ",  p->data);
	    p = p->next;
	}

	puts("");

	p = 0;
    }
}

void print_list_backwards(struct llist_t *list)
{
    struct node_t *p;

    if ((p = list->tail)) {

	while (p) {
	    printf("%d ", p->data);
	    p = p->prev;
	}

	puts("");

	p = 0;
    }
}

void free_list(struct llist_t *list)
{
    struct node_t *d;

    d = list->head;
    while ((d = list->head)) {
	list->head = list->head->next;
	free(d); d = 0;
    }

    free(list);
}

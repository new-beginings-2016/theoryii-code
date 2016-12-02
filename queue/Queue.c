/*
 *  Queue.c
 *
 *  Jason Graalum
 *  November 15, 2016
 *  New Beginnings - Theory II
 *
 *  Generic support for standard data structures used in a variety of programs
 *
 *  queue
 *
 *  The same data element(queueNode) is used for all structures. The queueNode structure
 *  include a void ptr to another structure that can be defined within the main program
 *  to hold program specific payloads
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Queue.h"

//
// Queue routines
//
struct queueNode* dequeue(struct Queue *p)
{
   struct queueNode *node;
   node = p->head;
   p->head = p->head->next;
   return(node);
}

void enqueue(struct Queue *q, struct queueNode *node)
{
   struct queueNode *current;
   current = q->head;
   node->next = NULL;

   if(!current)
   {
      q->head = node;
      return;
   }
   else
   {
      node->next = current;
      q->head = node;
      return;
   }
}

void enqueueMax(struct Queue *q, struct queueNode *node)
{
   struct queueNode *current;
   current = q->head;
   node->next = NULL;

   if(!current)
   {
      q->head = node;
      return;
   }
   if(current->key < node->key)
   {
      node->next = current;
      q->head = node;
      return;
   }
   
   while(current->next && (current->next->key > node->key))
      current = current->next;

   node->next = current->next;
   current->next = node;
   return;
}

void enqueueMin(struct Queue *q, struct queueNode *node)
{
   struct queueNode *current;
   current = q->head;
   node->next = NULL;

   if(!current)
   {
      q->head = node;
      return;
   }
   if(current->key > node->key)
   {
      node->next = current;
      q->head = node;
      return;
   }
   
   while(current->next && (current->next->key < node->key))
      current = current->next;

   node->next = current->next;
   current->next = node;
   return;
}
void printQueue(struct Queue *q)
{
   struct queueNode *node;
   node = q->head;
   while(node)
   {
      printf("%d: %u\n", node->index, node->key);
      node = node->next;
   }
}


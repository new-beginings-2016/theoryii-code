typedef struct queueNode {
   unsigned int key;
   unsigned int index;
   void *data;
   struct queueNode *next;
   struct queueNode *prev;
} queueNode;

typedef struct Queue {
   struct queueNode *head;
   struct queueNode *tail;
} Queue;

struct queueNode* dequeue(struct Queue*);
void enqueue(struct Queue*, struct queueNode*);
void enqueueMin(struct Queue*, struct queueNode*);
void enqueueMax(struct Queue*, struct queueNode*);
void printQueue(struct Queue*);

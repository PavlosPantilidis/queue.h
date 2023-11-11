#ifndef QUEUE_H
#define QUEUE_H

/* Libraries */
#include <stdio.h>
#include <stdlib.h>

/* Typedef */
typedef struct Queue* Queue;
typedef struct Queue* queue;

/* Structs */
struct Node {
    void *data;
    struct Node *next;
};

struct Queue {
    struct Node *front;
    struct Node *rear;
};

/* Functions */
struct Queue *initializeQueue(void);
int isEmpty(struct Queue *queue);
void enqueue(struct Queue *queue,void *data);
void *dequeue(struct Queue *queue);
void *front(struct Queue *queue);
void *rear(struct Queue *queue);
struct Queue *cloneQueue(struct Queue *queue);
void destroyQueue(struct Queue *queue);

#endif
/*######################################*/
/*                                      */
/*       Name: Pavlos Pantilidis        */
/*                                      */
/*             AM: csd4709              */
/*                                      */
/*######################################*/ 
#ifndef QUEUE_H
#define QUEUE_H

/* Libraries */
#include <stdio.h>
#include <stdlib.h>

struct QueueNode {
    void *data;
    struct QueueNode *next;
};

struct Queue {
    struct QueueNode *front;
    struct QueueNode *rear;
};

/* Functions */
struct Queue *MakeEmptyQueue();
int IsEmptyQueue(struct Queue *queue);
void Enqueue(struct Queue *queue,void *data);
void *Dequeue(struct Queue *queue);
void *Front(struct Queue *queue);
struct Queue *CloneQueue(struct Queue *queue);

#endif
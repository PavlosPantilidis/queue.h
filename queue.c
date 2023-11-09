/*######################################*/
/*                                      */
/*       Name: Pavlos Pantilidis        */
/*                                      */
/*             AM: csd4709              */
/*                                      */
/*######################################*/
#include "queue.h"

/* Function to create a new queue and initialize it */
struct Queue *MakeEmptyQueue() {
    struct Queue *newQueue = (struct Queue *)malloc(sizeof(struct Queue));

    if (!newQueue) {
        perror("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    newQueue->front = newQueue->rear = NULL;
    return newQueue;
}

/* Function to check if the queue is empty */
int IsEmptyQueue(struct Queue *queue) {
    return queue->front == NULL;
}

/* Function to enqueue an element into the queue */
void Enqueue(struct Queue *queue,void *data) {
    struct QueueNode *newNode = (struct QueueNode *)malloc(sizeof(struct QueueNode));

    if (!newNode) {
        perror("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = data;
    newNode->next = NULL;

    if (IsEmptyQueue(queue)) {
        queue->front = queue->rear = newNode;
    }
    else {
        queue->rear->next = newNode;
        queue->rear = newNode; 
    }
}

/* Function to dequeue an element from the queue */
void *Dequeue(struct Queue *queue) {
    if (IsEmptyQueue(queue)) {
        fprintf(stderr,"Queue is empty.\n");
        exit(EXIT_FAILURE);
    }

    struct QueueNode *temp = queue->front;
    void *data = temp->data;
    queue->front = queue->front->next;
    free(temp);

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    return data;
}

/* Function to get the front element of the queue */
void *Front(struct Queue *queue) {
    if (IsEmptyQueue(queue)) {
        fprintf(stderr,"Queue is empty.\n");
        exit(EXIT_FAILURE);       
    }

    return queue->front->data;
}

/* Function that return a clone of the queue */
struct Queue *CloneQueue(struct Queue *queue) {
    struct Queue *tmp = MakeEmptyQueue();
    struct QueueNode *current = queue->front;

    while (current != NULL) {
        Enqueue(tmp,current->data);
        current = current->next;
    }

    return tmp;
}
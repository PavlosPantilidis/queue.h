#include "queue.h"

/* Function to initialize an empty queue */
struct Queue *initializeQueue(void) {
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));

    if (!queue) {
        perror("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    queue->front = queue->rear = NULL;
    return queue;
}

/* Function to check if the queue is empty */
int isEmpty(struct Queue *queue) {
    return queue->front == NULL;
}

/* Function to add an element to the rear of the queue */
void enqueue(struct Queue *queue,void *data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (!newNode) {
        perror("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;
    }
    else {
        queue->rear->next = newNode;
        queue->rear = newNode; 
    }
}

/* Function to remove and return the element from the front of the queue */
void *dequeue(struct Queue *queue) {
    if (isEmpty(queue)) {
        fprintf(stderr,"Queue is empty.\n");
        exit(EXIT_FAILURE);
    }

    struct Node *temp = queue->front;
    void *data = temp->data;
    queue->front = queue->front->next;
    free(temp);

    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    return data;
}

/* Function to get the data at the front of the queue without removing it */
void *front(struct Queue *queue) {
    if (isEmpty(queue)) {
        fprintf(stderr,"Queue is empty.\n");
        exit(EXIT_FAILURE);       
    }
    return queue->front->data;
}

/* Function to get the data at the rear of the queue without removing it */
void *rear(struct Queue *queue) {
    if (isEmpty(queue)) {
        fprintf(stderr,"Queue is empty.\n");
        exit(EXIT_FAILURE);       
    }
    return queue->rear->data;
}

/* Function to clone a queue */
struct Queue *cloneQueue(struct Queue *queue) {
    struct Queue *tmp = initializeQueue();
    struct Node *current = queue->front;

    while (current != NULL) {
        enqueue(tmp,current->data);
        current = current->next;
    }
    return tmp;
}

/* Function to destroy the queue and free memory */
void destroyQueue(struct Queue *queue) {
    while(!isEmpty(queue)) {
        dequeue(queue);
    }
    free(queue);
}
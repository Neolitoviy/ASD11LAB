#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

#define MAX_QUEUE_SIZE 100

typedef struct Queue {
    int items[MAX_QUEUE_SIZE];
    int front;
    int rear;
} Queue;

Queue* createQueue();
bool isEmpty(Queue* queue);
void enqueue(Queue* queue, int value);
int dequeue(Queue* queue);

#endif
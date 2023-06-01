#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

bool isEmpty(Queue* queue) {
    return queue->rear == -1;
}

void enqueue(Queue* queue, int value) {
    if (queue->rear == MAX_QUEUE_SIZE - 1) {
        printf("Переповнення черги\n");
        return;
    }
    if (queue->front == -1) {
        queue->front = 0;
    }
    queue->rear++;
    queue->items[queue->rear] = value;
}

int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Черга порожня\n");
        return -1;
    }
    int item = queue->items[queue->front];
    queue->front++;
    if (queue->front > queue->rear) {
        queue->front = queue->rear = -1;
    }
    return item;
}
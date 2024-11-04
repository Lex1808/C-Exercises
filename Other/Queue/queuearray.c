#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define SIZE_ARRAY 100

struct queue_type {
    Item content[SIZE_ARRAY];
    int front, back, size;
};

static void terminate(const char *message) {
    printf("ERROR: %s\n", message);
    exit(EXIT_FAILURE);
}

Queue createQueue(void) {
    Queue q = malloc(sizeof(struct queue_type));
    if(q == NULL) {
        terminate("Create queue failed\n");
    }
    q->front = 0;
    q->back = -1;
    q->size = 0;

    return q;
}
void destroyQueue(Queue q) {
    free(q);
}
bool is_empty(Queue q) {
    return q->size == 0;
}
bool is_full(Queue q) {
    return q->size >= SIZE_ARRAY;
}
void enqueue(Queue q, Item i) {
    if(is_full(q)) {
        terminate("Queue overflow\n");
    }
    q->back = (q->back + 1) % SIZE_ARRAY;
    q->content[q->back] = i;
    q->size++;
}
Item dequeue(Queue q) {
    Item old;
    if(is_empty(q)) {
        terminate("Buffer underflow\n");
    }
    old = q->content[q->front];
    q->front = (q->front + 1) % SIZE_ARRAY;
    q->size--;

    return old;
}
Item front(Queue q) {
    if(is_empty(q)) {
        terminate("Queue is empty\n");
    }
    return q->content[q->front];
}
Item back(Queue q) {
    if(is_full(q)) {
        terminate("Queue is empty\n");
    }
    return q->content[q->back];
}

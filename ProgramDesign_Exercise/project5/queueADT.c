#include <stdio.h>
#include <stdlib.h>
#include "queueADT.h"

struct queue_type {
    Item *content;
    int front, back, size, max_size;
};

static void terminate(const char *message) {
    printf("ERROR: %s\n", message);
    exit(EXIT_FAILURE);
}

Queue createQueue(int size_array) {
    Queue q = malloc(sizeof(struct queue_type));
    if(q == NULL) {
        terminate("Create queue failed\n");
    }
    if((q->content = malloc(size_array * sizeof(Item))) == NULL) {
        terminate("Malloc filed in queue_create\n");
    }
    q->front = 0;
    q->back = -1;
    q->size = 0;
    q->max_size = size_array;

    return q;
}
bool destroyQueue(Queue q) {
    if(q == NULL) {
        terminate("Queue doesn't exist");
    }
    free(q->content);
    free(q);
    
    return true;
}
bool is_empty(Queue q) {
    return q->size == 0;
}
bool is_full(Queue q) {
    return q->size >= q->max_size;
}
void enqueue(Queue q, Item i) {
    if(is_full(q)) {
        terminate("Queue overflow\n");
    }
    q->back = (q->back + 1) % q->max_size;
    q->content[q->back] = i;
    q->size++;
}
void dequeue(Queue q) {
    if(is_empty(q)) {
        terminate("Buffer underflow\n");
    }
    q->front = (q->front + 1) % q->max_size;
    q->size--;
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

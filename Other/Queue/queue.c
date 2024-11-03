#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

struct node {
    Item data;
    struct node *next;
};

struct queue_type {
    struct node *front, *back;
};

static void terminate(const char *message) {
    printf("ERROR: %s", message);
    exit(EXIT_FAILURE);
}

Queue createQueue(void) {
    Queue q = malloc(sizeof(struct queue_type));
    if (q == NULL) {
        terminate("Queue create failure\n");
    }
    q->front = q->back = NULL;
    return q;
}

bool destroyQueue(Queue q) {
    if(q == NULL) {
        terminate("Queue does not exist\n");
    }
    while(!is_empty(q)) {
        dequeue(q);
    }
    free(q);
    return true;
} 
bool is_empty(Queue q) {
    return q->front == NULL && q->back == NULL;
}
bool is_full(Queue q) {
    return false;
}
void enqueue(Queue q, Item i) { // Adds an item to the end of the queue
    struct node *new_node = malloc(sizeof(struct node));
    if (new_node == NULL) {
        terminate("Create new node failure\n");
    }
    new_node->data = i;
    new_node->next = NULL;
    if(is_empty(q)) {
        q->front = q->back = new_node;
        return;
    }
    q->back->next = new_node;
    q->back = new_node; 
}
void dequeue(Queue q) { // Removes an item from the beginning of the queue
    struct node *old_node;
    if (is_empty(q)) {
        terminate("Buffer underflow\n");
    }
    old_node = q->front;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->back = NULL;
    }

    free(old_node);
} 
Item front(Queue q) { // Returns the first item in the queue (without deleting)
    if (is_empty(q)) {
        terminate("First element doesn't find.Queue is empty\n");
    }
    return q->front->data;
} 

Item back(Queue q) { // Returns the last item in the queue (without deleting)
    if (is_empty(q)) {
        terminate("Last elsement doesn't find. Queue is empty\n");
    }
    return q->back->data;
}

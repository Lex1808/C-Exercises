#include <stdio.h>
#include <stdlib.h>
#include "queueADT.h"

struct node {
    Item data;
    struct node *next;
};

struct queue_type {
    struct node *front;
    struct node *back;
};

static void terminate(const char *message) {
    printf("ERROR: %s\n", message);
    exit(EXIT_FAILURE);
}

Queue createQueue(void) {
    Queue q = malloc(sizeof(struct queue_type));
    if (q == NULL) {
        terminate("Failure creating queue. Memory segmentation error");
    }
    q->front = q->back = NULL;

    return q;
}
bool destroyQueue(Queue q) {
    if(q == NULL) {
        terminate("Queue doesn't exist.");
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

void enqueue(Queue q, Item i) {
    struct node *new_node = malloc(sizeof(struct node));
    if (new_node == NULL) {
        terminate("Enqueue failed. Segmentation fault");
    }
    new_node->data = i;
    new_node->next = NULL;
    if(is_empty(q)) {
        q->front = q->back = new_node;
    } else {
        q->back->next = new_node;
        q->back = new_node;
    }
}

void dequeue(Queue q) {
    struct node *old_node;
    if(is_empty(q)) {
        terminate("Queue buffer underflow");
    }
    old_node = q->front;
    q->front = q->front->next;
    if(q->front == NULL) {
        q->back = NULL;
    } 

    free(old_node);
}

Item front(Queue q) {
    if(is_empty(q)) {
        terminate("First element not find. Check it queue exist status");
    }
    return q->front->data;
}

Item back(Queue q) {
    if(is_empty(q)) {
        terminate("Last element not find. Check it queue exist status");
    }
    return q->back->data;
}

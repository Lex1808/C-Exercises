#ifndef QUEUEADT_H
#define QUEUEADT_H

#include <stdbool.h>

typedef int Item;
typedef struct queue_type *Queue;

Queue createQueue(void); 
bool destroyQueue(Queue q); 
bool is_empty(Queue q);
bool is_full(Queue q);
void enqueue(Queue q, Item i); 
void dequeue(Queue q); 
Item front(Queue q); 
Item back(Queue q); 

#endif

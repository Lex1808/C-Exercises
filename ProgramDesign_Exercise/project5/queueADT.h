#ifndef QUEUEADT_H
#define QUEUEADT_H

#include <stdbool.h>

typedef int Item;
typedef struct queue_type *Queue;

Queue createQueue(int size_array); 
bool destroyQueue(Queue q); 
bool is_empty(Queue q);
bool is_full(Queue q);
void enqueue(Queue q, Item i); // Adds an item to the end of the queue
void dequeue(Queue q); // Removes an item from the beginning of the queue
Item front(Queue q); // Returns the first item in the queue (without deleting)
Item back(Queue q); // Returns the last item in the queue (without deleting)

#endif

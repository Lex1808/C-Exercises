#include <stdio.h>
#include "queue.h"

int main(void) {
    Queue q = createQueue();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    printf("Get first: %d\n", front(q));
    printf("Get last: %d\n", back(q));
    
    while(!is_empty(q)) {
        dequeue(q);
    }
    printf("Queue is empty\n");

    enqueue(q, 40);
    enqueue(q, 50);

    printf("Get first: %d\n", front(q));
    printf("Get last: %d\n", back(q));

    if(destroyQueue(q) == true) {
        printf("Queue was destroyed\n");
    } else {
        printf("Invalid operation\n");
    }

    return 0;
}

#include <stdio.h>
#include "queueADT.h"

int main(void) {
    Queue q1, q2;
    int queue_elements;

    q1 = createQueue();
    q2 = createQueue();
    
    enqueue(q1, 1);
    enqueue(q1, 2);
    enqueue(q1, 3);
    if (is_empty(q1)) {
        printf("Error enqueue operation\n");
    } else {
        printf("Successful enqueue operation\n");
    }

    while(!is_empty(q1)) {
        queue_elements = front(q1);
        dequeue(q1);
        printf("Dequeue element %d from q1\n", queue_elements);
        enqueue(q2, queue_elements);
    }
    if(destroyQueue(q1) == true) {
        printf("q1 was destroyed success\n");
    } else {
        printf("Error destroy queue\n");
    }

    while(!is_empty(q2)) {
        printf("Dequeue element %d from q2\n", front(q2));
        dequeue(q2);
    }

    enqueue(q2, 777);
    if(is_empty(q2)) {
        printf("Queue is empty\n");
    } else {
        printf("q2 have element %d in queue\n", front(q2));
    }

    if(destroyQueue(q2) == true) {
        printf("q2 was destroyed success\n");
    } else {
        printf("Error destroy queue\n");
    }

    printf("Element in q2 %d", front(q2));
    
    return 0;
}

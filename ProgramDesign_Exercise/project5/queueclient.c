#include <stdio.h>
#include "queueADT.h"

int main(void) {
    Queue q1, q2;
    int f, b;

    q1 = createQueue(3);
    q2 = createQueue(5);

    enqueue(q1, 380);
    enqueue(q1, 5555);
    enqueue(q2, 66788);

    f = front(q1);
    dequeue(q1);
    printf("Front element: %d\n", f);
    enqueue(q2, f);
    b = back(q1);
    dequeue(q1);
    printf("Back element: %d\n", b);
    enqueue(q2, b);

    if(is_empty(q1)) {
        destroyQueue(q1);
        printf("Queue was destroyed\n");
    } else {
        printf("Queue is not empty. Make empty please!\n");
    }

    while(!is_empty(q2)) {
        printf("Dequeue from q2: %d\n", front(q2));
        dequeue(q2);
    }

    enqueue(q2, 7);
    if(is_empty(q2)) {
        printf("Queue is empty\n");
    } else {
        printf("Queue is not empty\n");
    }

    if((destroyQueue(q2)) == true) {
        printf("q2 was destroyd\n");
    } else {
        printf("Failed q2 destroy\n");
    }

    return 0;    
}

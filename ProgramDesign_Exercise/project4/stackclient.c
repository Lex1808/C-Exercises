#include <stdio.h>
#include "stackADT.h"

int main(void)
{
    Stack s1, s2;
    char *n;

    s1 = create();
    s2 = create();

    push(s1, "hello");
    push(s1, "world");

    printf("Elements in first stack: %d and second: %d\n", length(s1), length(s2));
    printf("Last element: %s\n", peek(s1));

    n = pop(s1);
    printf("Popped %s from s1\n", n);
    push(s2, n);
    n = pop(s1);
    printf("Popped %s from s1\n", n);
    push(s2, n);

    destroy(s1);

    while(!is_empty(s2)) {
        printf("Popped %s from s2\n", pop(s2));
    }

    push(s2, "You are programmer Harry");
    printf("Elements in second stack: %d\n", length(s2));
    make_empty(s2);
    if (is_empty(s2)) {
        printf("s2 is empty\n");
    } else {
        printf("s2 is not empty\n");
    }

    destroy(s2);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "stackADT.h"

#define STACK_SIZE 100

struct stack_type {
    Item contents[STACK_SIZE];
    int top;
};

static void terminate(const char *message) {
    printf("ERROR: %s\n", message);
    exit(EXIT_FAILURE);
}

Stack create(void) {
    Stack s = malloc(sizeof(struct stack_type));
    if (s == NULL) {
        terminate("Stack create failure");
    }
    s->top = 0;

    return s;
}

void destroy(Stack s) {
    free(s);
}
void make_empty(Stack s) {
    s->top = 0;
}
bool is_empty(Stack s) {
    return s->top == 0;
}
bool if_full(Stack s) {
    return s->top == STACK_SIZE;
}

void push(Stack s, int i) {
    if (is_full(s)) {
        terminate("Buffer overflow!");
    }
    s->contents[s->top++] = i;
}
int pop(Stack s) {
    if (is_empty(s)) {
        terminate("Buffer underflow");
    }
    return s->contents[--s->top];
}

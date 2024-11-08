#include <stdio.h>
#include <stdlib.h>
#include "stackADT.h"

struct node {
    void *data;
    struct node *next;
};

struct stack_type {
    int len;
    struct node *top;
};

static void terminate(const char *message) {
    printf("ERROR: %s\n", message);
    exit(EXIT_FAILURE);
}

Stack create(void) {
    Stack s = malloc(sizeof(struct stack_type));
    if (s == NULL) {
        free(s);
        terminate("Stack create failure");
    }
    s->top = NULL;
    s->len = 0;

    return s;
}

void destroy(Stack s) {
    make_empty(s);
    free(s);
}

void make_empty(Stack s) {
    while(!is_empty(s)) {
        pop(s);
        --s->len;
    }
}

bool is_empty(Stack s) {
    return s->top == NULL && s->len == 0;
}
bool is_full(Stack s) {
    return false;
}

void push(Stack s, void *i) {
    struct node *new_node = malloc(sizeof(struct node));
    if (new_node == NULL) {
        terminate("Stack if full.");
    }
    s->len++;
    new_node->data = i;
    new_node->next = s->top;
    s->top = new_node;
}

void *pop(Stack s) {
    struct node *prev_top;
    void *i;

    if(is_empty(s)) {
        terminate("Stack is empty");
    }
    prev_top = s->top;
    i = prev_top->data;
    s->top = prev_top->next;
    --s->len;
    free(prev_top);

    return i;
}

void *peek(Stack s) {
    if (is_empty(s)) {
        terminate("Stack is empty\n");
    }
    return s->top->data;
}

int length(Stack s) {
    return s->len;
}

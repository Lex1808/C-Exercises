#include <stdio.h>
#include <stdlib.h>
#include "stackADT.h"

struct node {
    Item data;
    struct node *next;
};

struct stack_type {
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

    return s;
}

void destroy(Stack s) {
    make_empty(s);
    free(s);
}

void make_empty(Stack s) {
    while(!is_empty(s)) {
        pop(s);
    }
}

bool is_empty(Stack s) {
    return s->top == NULL;
}
bool is_full(Stack s) {
    return false;
}

void push(Stack s, Item i) {
    struct node *new_node = malloc(sizeof(struct node));
    if (new_node == NULL) {
        terminate("Stack if full.");
    }
    new_node->data = i;
    new_node->next = s->top;
    s->top = new_node;
}

Item pop(Stack s) {
    struct node *prev_top;
    Item i;

    if(is_empty(s)) {
        terminate("Stack is empty");
    }
    prev_top = s->top;
    i = prev_top->data;
    s->top = prev_top->next;
    free(prev_top);

    return i;
}

Item peek(Stack s) {
    if (is_empty(s)) {
        terminate("Stack is empty\n");
    }
    return s->top->data;
}

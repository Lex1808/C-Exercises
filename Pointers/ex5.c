#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


struct stack {
    int value;
    struct stack *next_node;
};
struct stack *top = NULL;


void make_empty(void)
{
    struct stack *temp;

    while(top != NULL) {
        temp = top;
        top = top->next_node;
        free(temp);
    }
}

bool is_empty(void)
{
    return top == NULL;
}

bool push(int i)
{
    struct stack *new_node;
    new_node = malloc(sizeof(struct stack));
    if(new_node == NULL) {
        return false;
    }
    new_node->value = i;
    new_node->next_node = top;
    top = new_node;

    return true;
}

int pop(void)
{
    struct stack *temp;
    int i;
    if(is_empty()) {
        fprintf(stderr, "Stack underflow");
        exit(EXIT_FAILURE);
    }
    i = top->value;
    temp = top;
    top = top->next_node;
    free(temp);

    return i;
}

int main(void)
{   
    int value;
    int iteration = 3;
    for (int i = 0; i < iteration; i++) {
        scanf("%d", &value);
        push(value);
    }

    for (int i = 0; i < iteration; i++) {
        printf("return %d\n", pop());
    }

    return 0;
}


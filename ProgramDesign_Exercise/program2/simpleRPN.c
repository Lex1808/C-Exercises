#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"


int evaluate_RPN_expression(const char *expression) {
    Stack s = create();
    int operand1;
    int operand2;

    while(*expression) {
        if(isdigit(*expression)) {
            push(s, *expression - '0');
        } else {
            switch (*expression)
            {
            case '+': push(s, pop(s) + pop(s));
                break;
            case '-': operand2 = pop(s); operand1 = pop(s); push(s, operand1 - operand2);
                break;
            case '*': push(s, pop(s) * pop(s));
                break;
            case '/': operand2 = pop(s); operand1 = pop(s);
                if(operand2 == 0) {
                    printf("Division by zero\n");
                    exit(EXIT_FAILURE);
                }
                push(s, operand1 / operand2);
                break;
            case '=': return pop(s);
                break;
            case ' ':
                break;
            
            default: exit(EXIT_FAILURE);
                break;
            }
        }
        expression++;
    }
    free(s);

    fprintf(stderr, "ERROR: Invalid expression\n");
    exit(EXIT_FAILURE);
}

int main(void) {
    char ch, *p, *expr;

    while(1) {
        expr = malloc(100 * sizeof(char));
        if (expr == NULL) {
            exit(EXIT_FAILURE);
        }
        p = expr;
        printf("Enter exprasion: ");
        while((ch = getchar()) != '\n') {
            *p++ = ch;
        }
        *p = '\0';

        if (strcmp(expr, "exit") == 0) {
            printf("Thank you\n");
            return 0;
        } else {
            printf("Result: %d\n", evaluate_RPN_expression(expr));
        }

        free(expr);
    }

    exit(EXIT_SUCCESS);
}

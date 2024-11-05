#include <stdio.h>
#include "stackADT.h" 

int main(void) {

    char current;
    Stack bracket_stack;

    bracket_stack = create();
    printf("Enter parentheses and/or braces: ");
    
    while ((current = getchar()) != '\n') {
        if (current == EOF) {
            fprintf(stderr, "Error reading input.\n");
            return 1; 
        }
        if (current == '}' || current == ')') {
            if(is_empty(bracket_stack) || pop(bracket_stack) != (current == '}' ? '{': '(')) {
                printf("Parentheses/braces are not nested properly\n");
                destroy(bracket_stack);
                return 0;
            }
        } else if(current == '{' || current == '(') {
            push(bracket_stack, current);
        }      
    }
    
    if (!is_empty(bracket_stack)) {
        printf("Parentheses/braces are not nested properly\n");
        destroy(bracket_stack);
        return 0;
    }

    printf("Parentheses/braces are nested properly\n");
    destroy(bracket_stack);

    return 0;
}

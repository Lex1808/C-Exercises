#include <stdio.h>
#include <stdlib.h>

struct point {
    int x;
    int y;
};
struct rectangle {
    struct point upper_left;
    struct point lower_right;
};
int main(void) {
    struct rectangle *p;
    struct rectangle *temp_node = malloc(sizeof(struct rectangle));
    if (temp_node == NULL) {
        fprintf(stderr, "Error memory allocated");
        exit(EXIT_FAILURE);
    }
    p = temp_node;

    p->upper_left.x = 10;
    p->upper_left.y = 25;

    p->lower_right.x = 20;
    p->lower_right.y = 15;

    printf("upper_left: (%d, %d)\n", p->upper_left.x, p->upper_left.y);
    printf("lower_right: (%d, %d)\n", p->lower_right.x, p->lower_right.y);

    free(p); //or free(temp_node);

    return 0;
}

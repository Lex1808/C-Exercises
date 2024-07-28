/*Exercises
In the following declarations, the x and y sUuctures have members named x and y:
struct { int x, y;} x;
struct { int x, y;} y;
Are these declarations legal on an individual basis? Could both declarations appear as shown in a program? 
Justify your answer
*/
#include <stdio.h>

int main(void) {
    struct {
        int x, y;
    } x;

    struct {
        int y, x;
    } y;

    x.x = 82;
    x.y = 90;
    y.y = 30;
    y.x = 52;

    printf("Struct x.x: %d, Struct x.y: %d\n", x.x, x.y);
    printf("Struct y.y: %d, Struct y.x: %d\n", y.y, y.x);

    return 0;
}

#include <stdio.h>

#define SHIFT_BIT 1
#define CTRL_BIT 2
#define ALT_BIT 4

int main(void) {
    int bits = 2;

    if ((bits & (SHIFT_BIT | CTRL_BIT | ALT_BIT)) == 0) {
        printf("No modifier keys pressed\n");
    }
}

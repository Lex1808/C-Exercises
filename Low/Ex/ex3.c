#include <stdio.h>

#define M(x,y) ((x) ^= (y), (y) ^= (x), (x) ^= (y)) // 00000010               000010000                 000010010
                                                    //          x = 000010010            y = 000000010             x = 000010000
                                                    // 00010000               000010010                 000000010

int main(void)
{
    unsigned short int x = 2; // 0000000000000010
    unsigned short int y = 16; // 0000000000001000

    // Swap x and y
    M(x, y);
    
    printf("x = %d and y = %d\n", x, y);
}

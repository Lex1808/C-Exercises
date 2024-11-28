// [1] Show the output produced by each of the following program fragments. Assume that i, j. and k are unsigned short variables.
#include <stdio.h>

int main(void)
{
    unsigned short int i = 8; // 0000000000001000
    unsigned short int j = 9; // 0000000000001001
    unsigned short int k;

    printf("%d\n", (i >> 1) + (j >> 1)); //  0000000000000100 + 0000000000000100 == 8;

    i = 1; // 0000000000000001

    printf("%d\n", i & ~i); // 0000000000000001 AND 1111111111111110 == 0;

    i = 2; // 0000000000000010
    j = 1; // 0000000000000001
    k = 0; // 0000000000000000

    printf("%d\n", (~i) & (j ^ k)); // 1111111111111101 AND 000000000000001 = 0000000000000000 == 1;

    i = 7; // 0000000000000111
    j = 8; // 0000000000001000
    k = 9; // 0000000000001001

    printf("%d\n", (i ^ j) & k); // 0000000000001111 AND 0000000000001001 = 0000000000001001 == 6; 
}

#include <stdio.h>

int main(void)
{
    unsigned short int i;
    i = 0x0000;
    i |= 0x0010;

    if (i & 0x0010) {
        printf("%d", i);
    } else {
        printf("Wrong!");
    }
    
}

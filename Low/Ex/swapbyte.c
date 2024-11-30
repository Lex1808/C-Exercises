#include <stdio.h>

unsigned short swap_byte(unsigned short i) {

    return ((i & 0xFF00) >> 8 | (i & 0x00FF) << 8);
}

int main(void)
{
    unsigned short byte;

    do
    {
        printf("Enter value: ");
        scanf("%hx", &byte);

        byte = swap_byte(byte);
        printf("%hx\n", byte);
    } while (byte != 0x000);
    
    return 0;
}

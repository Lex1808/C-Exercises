#include <stdio.h>

unsigned short create_short(unsigned char high_byte, unsigned char low_byte) {
    return (high_byte << 8) + low_byte;
}

int main(void) {
    unsigned char h_byte = 'a';
    unsigned char l_byte = 'b';

    printf("%x\n", create_short(h_byte, l_byte));

    return 0;
}

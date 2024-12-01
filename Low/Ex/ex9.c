#include <stdio.h>

void binary(unsigned char ch) {
    int num = ch;
    int i;
    for (i = 8; i >= 0; --i) {
        if (num & (1 << i)) {
            putchar('1');
        } else {
            putchar('0');
        }
    }
    printf("\n");
    
}

int count_ones(unsigned char ch) {
    int bit = ch;
    int count = 0;
    int i;

    for (i = 7; i >= 0; --i) {
        if (bit & (1 << i)) {
            count++;
        }
    }

    return count;
}

int count_ones2(unsigned char ch) {
    ch = ch - ((ch >> 1) & 0x55);
    ch = (ch & 0x33) + ((ch >> 2) & 0x33);
    return ((ch + (ch >> 4)) & 0x0F) % 255;
}

int main(void) {
    unsigned char ch = 'a';

    binary(ch);
    printf("%d\n", count_ones(ch));
    printf("%d\n", count_ones2(ch));

    return 0;
}

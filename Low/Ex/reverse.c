#include <stdio.h>

unsigned int reverse_bits(unsigned int n) {
    unsigned int result = 0;
    for (int i = 31; i >= 0; --i) {
        if (n & (1 << i)) {
            result |= 1 << (31 - i);
        }
    }
    return result;
}

int main(void) {
    unsigned int bits = 0b10110010;
    printf("%x\n", reverse_bits(bits));

    return 0;
}

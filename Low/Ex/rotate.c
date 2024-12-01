#include <stdio.h>

unsigned int rotate_left(unsigned int i, int n) {
    return ((i << n) | ((i & 0xFFFFFF00) >> (32 - n)));
}

unsigned int rotate_right(unsigned int i, int n) {
    return (i >> n) | ((i & 0x00FFFFFF) << (32 - n));
}

int main(void) {
    unsigned int bytes;
    int bitwise;

    printf("Enter value: ");
    scanf("%x", &bytes);
    printf("Enter bitwise value: ");
    scanf("%d", &bitwise);

    bytes = rotate_left(bytes, bitwise);
    printf("Value: %x\n", bytes);

    return 0;
}

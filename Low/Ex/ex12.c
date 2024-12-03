#include <stdio.h>

struct float_num {
    unsigned int sign: 1;
    unsigned int exponent: 8;
    unsigned int fraction: 23; 
};

int main(void)
{
    float num = 5.14f;
    unsigned int *p_num = (unsigned int *)&num;
    struct float_num *f_num = (struct float_num *)p_num;

    printf("Sign: %u\n", f_num->sign);
    printf("Exponent: %u\n", f_num->exponent);
    printf("Fraction: %u\n", f_num->fraction);

    return 0;
}

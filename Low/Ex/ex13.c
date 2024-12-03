#include <stdio.h>

struct flags {
    unsigned int flag: 1; // for correct behavior on different systems, you need to use an unsigned type. 
} s;

int main(void)
{
    s.flag = 1;

    printf("%d\n", s.flag);

    return 0;
}

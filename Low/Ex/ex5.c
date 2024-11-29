#include <stdio.h>

#define RED(x) ((x) & 0x00ff)
#define GREEN(x) ((x) >> 8 & 0x00ff)
#define BLUE(x) ((x) >> 16 & 0x00ff)

int main(void)
{
  return 0;
}

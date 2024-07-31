#include <stdio.h>

struct color {
    int red;
    int green;
    int blue;
}

struct color make_coloor(int red, int green, int blue) {
    struct color c;

    c.red = red;
    c.green = green;
    c.blue = blue;

    c.red = (c.red < 0) ? 0: (c.red > 255) ? 255: c.red;
    c.green = (c.green < 0) ? 0: (c.green > 255) ? 255: c.red;
    c.blue = (c.blue < 0) ? 0: (c.blue > 255) ? 255: c.red;

    return c;
}

int getRed(struct color c) {
    return c.red;
}

bool equal_color(struct color color1, struct color color2) {
    return (colorl.red == color2.red && color1.green == color2.green && color1.blue && color2.blue);
}

struct color brighter(struct color c) {
    if (c.red == 0 && c.green == 0 && c.blue == 0) {
        return (struct color) {3, 3, 3};    
    }

    if (c.red > 0 && c.red < 3) {
        c.red = 3;
    }
    if (c.green > 0 && c.green < 3) {
        c.green = 3;
    }
    if (c.blue > 0 && c.blue < 3) {
        c.blue = 3;
    }

    c.red = (int) c.red / 0.7;
    c.green = (int) c.green / 0.7;
    c.blue = (int) c.blue / 0.7;

    if (c.red > 255) {
        c.red = 255;
    }
    if(c.green > 255) {
        c.green = 255;
    }
    if(c.blue > 255) {
        c.blue = 255;
    }

    return c;
    
}

struct color darker(struct  color c) {
    c.red = (int) c.red * 0.7;
    c.green = (int) c.green * 0.7;
    c.blue = (int) c.blue * 0.7;

    return c;
}

int main(void) {
  //Other code
  return 0;
}

Suppose that the following declarations are in effect:\n
struct point { int x, y; };\n
struct rectangle { struct point upper_left, lower_right; };\n
struct rectangle *p;\n
Assume that we want p to point to a rectangle stnicture whose upper left comer is at (10. 25) and whose lower right comer is at (20. 15).\n 
Write a series of statements that allocate such a structure and initialize it as indicated.

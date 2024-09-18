Suppose that the following declarations are in effect:<br>
struct point { int x, y; };<br>
struct rectangle { struct point upper_left, lower_right; };<br>
struct rectangle *p;<br>
Assume that we want p to point to a rectangle stnicture whose upper left comer is at (10. 25) and whose lower right comer is at (20. 15).<br>
Write a series of statements that allocate such a structure and initialize it as indicated.

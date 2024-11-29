[1] Show the output produced by each of the following program fragments. Assume that i, j. and k are unsigned short variables. <br>
[2] Describe a simple way to "toggle" a bit (change it from 0 to 1 or from I to 0). Illustrate the technique by writing a statement that toggles bit 4 of the variable i. <br>
[3] Explain what effect the following macro has on its arguments. You may assume that the arguments have the same type. <br>
  #def ine M (x,y) ((x) ^= (y), (y) ^= (x), (x) ^= (y)) <br>
[4] In computer graphics, colors are often stored as three numbers, representing red, green, and blue intensities. Suppose that each number requires eight bits, and we'd <br>
like to store all three values in a single long integer. Write a macro named MK COLOR with three parameters (the red. green, and blue intensities). <br>
MK_COLOR should return a long in which the last three bytes contain the red. green, and blue intensities, with the red value as the last byte and the green value as the next-to-last byte <br>
[5] Write macros named GET RED. GET_GREEN. and GET BLUE that, when given a color as an argument (see Exercise 4), return its 8-bit red. green, and blue intensities. <br>

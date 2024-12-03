[1] Show the output produced by each of the following program fragments. Assume that i, j. and k are unsigned short variables. <br>
[2] Describe a simple way to "toggle" a bit (change it from 0 to 1 or from I to 0). Illustrate the technique by writing a statement that toggles bit 4 of the variable i. <br>
[3] Explain what effect the following macro has on its arguments. You may assume that the arguments have the same type. <br>
  #def ine M (x,y) ((x) ^= (y), (y) ^= (x), (x) ^= (y)) <br>
[4] In computer graphics, colors are often stored as three numbers, representing red, green, and blue intensities. Suppose that each number requires eight bits, and we'd <br>
like to store all three values in a single long integer. Write a macro named MK COLOR with three parameters (the red. green, and blue intensities). <br>
MK_COLOR should return a long in which the last three bytes contain the red. green, and blue intensities, with the red value as the last byte and the green value as the next-to-last byte <br>
[5] Write macros named GET RED. GET_GREEN. and GET BLUE that, when given a color as an argument (see Exercise 4), return its 8-bit red. green, and blue intensities. <br>
[6] (a) Use the bitwise operators to write the following function: <br>
unsigned short swap_bytes(unsigned short i); <br>
swap bytes should return the number that results from swapping the two bytes in i.(Short integers occupy two bytes on most computers.) For example, <br>
if i has the value 0x1234 (00010010 00110100 in binary), then swap_bytes should return 0x3412 (00110100 00010010 in binary). <br>
[7] Write the following functions: <br>
unsigned int rotate_left(unsigned int i, int n); <br>
unsigned int rotate_right(unsigned int i, int n); <br>
rotate left should return the result of shifting the bits in i to the left by n places, with the bits that were "shifted off moved to the right end of i. <br>
(For example, the call rotate_left(0x12345678, 4) should return 0x23456781 if integers are 32 bits long.) rotate right is similar, but it should "rotate” bits to the right instead of the left. <br>
[8] (a) Write the following function: <br>
int count_ones(unsigned char ch); <br>
count ones should return the number of 1 bits in ch. <br>
(b) Write die function in part (a) without using a loop. <br>
[9] Write the following function: <br>
unsigned int reverse_bits(unsigned int n); <br>
reverse_bits should return an unsigned integer whose bits are the same as those in n but in reverse order. <br>
[10] Each of the following macros defines the position of a single bit within an integer: <br>
#define SHIFT_BIT 1 <br>
#define CTRL_BIT 2 <br>
#define ALT_BIT 4 <br>
The following statement is supposed to test whether any of the three bits have been set. but it never displays the specified message. Explain why the statement doesn’t work and show <br>
how to fix it. Assume that key_code is an int variable. <br>
if (key_code & (SHIFT_BIT | CTRL_BIT | ALT_BIT) == 0) <br>
printf("No modifier keys pressed\n"); <br>
[11] The following function supposedly combines two bytes to form an unsigned short integer. Explain why the function doesn't work and show how to fix it. <br>
unsigned short create_short(unsigned char high_byte, unsigned char low_byte) <br>
return high_byte << 8 + low byte; <br>
} <br>
[12] When stored according to the IEEE floating-point standard, a float value consists of a 1-bit sign (the leftmost—or most significant—bit), an 8-bit exponent, <br> 
and a 23-bit fraction, in that order. Design a structure type that occupies 32 bits, with bit-field members corresponding to the sign, exponent, and fraction. <br>
Declare the bit-fields to have type unsigned int. <br>
Check the manual for your compiler to determine the order of the bit-fields. <br>

Write a function named my_malloc that serves as a “wrapper” for malloc.\n 
When we call my__malloc and ask it to allocate n bytes, it in turn calls malloc,\n 
tests to make sure that malloc doesn't return a null pointer, and then returns the pointer from malloc.\n 
Have my__malloc print an error message and terminate the program if malloc returns a null pointer.

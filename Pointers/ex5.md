Modify stack.c so that a stack is now stored as a linked list.<br> 
Replace the contents and top variables by a single variable that<br> 
points to the first node in the list (the "top” of the stack).<br> 
Write the functions in stack.c so that they use this pointer.<br> 
Remove the is full function, instead having push return either true<br> 
(if memory was available to create a node) or false (if not).

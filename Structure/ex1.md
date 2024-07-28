Exercises

In the following declarations, the x and y sUuctures have members named x and y:
struct { int x, y;} x;

struct { int x, y;} y;
Are these declarations legal on an individual basis? Could both declarations appear as shown in a program? Justify your answer

Answer
1. Yes, such a record is legal.
   According to the naming rules, the C language allows you to identify variables and members of structures by the same name if they have different scopes.
   
2. Although this is technically allowed, it is not recommended.This complicates the maintenance, support, and readability of the code in the future.
   Respect the team members who will read your code =)  

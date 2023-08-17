
/*an automatic variable will destroyed when a block or region that a variable is  declared, 
defined and used and when that block or region ends. its major benefit is that it doesnt waste any memory. 
for example;

#include <stdio.h>                         #include <stdio.h>{

int main() {                               int main();   

int var;                                   auto int var;
return 0;             is equal to          return 0;
                                        

}                                          }

*/

/* if u wont initialize auto variable it will be initialized with some garbage(random) value. 
for example, i u print that code;

#include <stdio.h>
int main() {

int var;
printf("%d", var);
return 0;
}

and global variables will be initialized 0 by default.

*/

/* int var;---->declaration and definition(declaring this variable and its type and ask compiler to allocate memory for it)
   extern int var; ---->just declaration. it is a way to use a variable which is defined in somewhere -in other file that in the same project- 
   when you dont want to define the var again. it will be reused without defining. this will save the memory and provide re-usability*/

/*multiple declarations are allowed but multiple definitions are not allowed*/

/*if i declare and define a variable (int a = 9;) 
  then say print an external variable (extern int a;
                                       printf("%d", a) it  will print 9. because external variable simply
to compiler, go outside from my scope, and you will find the definition of  the variable that i declared. so, it looks at the same file firstly.) */





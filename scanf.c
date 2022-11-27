
/*scanf stands for SCAN Formatted string
It accepts character, string and numeric data from the user using standart input-KEYBOARD*/

/*while scanning the input, scanf needs to store that input data somewhere. 
To store this input data, scanf needs to know the memory location of a variable.
   btw the usage is like that:
   
    int var;
    scanf("%d",&var);

the reason of putting &(ampersand) is that: & is also called as address-of operator.If you write &var = address of var and
Adress of variable means, asking for address of variable not the content of variable. When we write the name of variable
it is simply means that we are asking for content of variable. But when we write ampersand variable, we are asking for
address of the variable and not the content of the variable.*/

#include <stdio.h>

int main(){

int a, b;

printf("Enter the first number,\n");
scanf("%d", &a);
printf("Enter the second number,\n");
scanf("%d", &b);
printf("%d + %d = %d", a, b, a+b);
return 0;
}

/*conditional operator is ternary operator therefore it requires 3 operands

look and feel  ? : */

/*char result;
int marks;

if(marks > 33)
{
    result = 'p';
}
else
{
    result = 'f';
}

//the code above is same as the code bottom

char result;
int marks;

result = (marks > 33) ? 'p' : 'f';

/*conditional operator is the only ternary operator in C language.
 As in Expression1 ? Expresiion 2 : Expression 3   expression 1 is boolean expression.If we simply write 0 instead of some
 boolean expression then that simply means FALSE and therefore expression3 will get evaulated*/


#include <stdio.h>

int main(){
int var = 75;
int var2 = 56;
int num;

num = sizeof(var) ? (var2 > 23 ? ((var == 75) ? 'A' : 0) : 0 ) : 0;

printf("%d", num);
return 0;
}
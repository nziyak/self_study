/*to increment some value by one we use ++
  to decrement some value by one we use --
  for example;
  
  int a = 5;             int a = 5;
  a++;                   a--;
  now a = 6              now a = 4  
  
  a++ is same as a = a+1
  a-- is same as a = a-1

  and ++ and -- are unary operators, that is, they can be applied only one operand. so a ++ a is a wrong usage.
  ++a is pre-increment operator,  a++ is post-increment operator. its same for decrement. 
  pre increment/decrement means ++/-- will be applied before the operand. 
  post increment/decrement means ++/-- will be applied after the operand.

  and you can not write (a+b)++; or ++(a+b); to understand why, look at the 22. video.

  so basically the difference between pre-increment and post increment operator is first increment then assign it to another
  value.

  and in equations things a little change. 
  post-increment/decrement in context of equation: first use the value in equation then increment value.
  pre-increment/decrement in context of equation: first increment the value and then use in the equation after completion of equation.
  */

 #include <stdio.h>

 int main(){

 int a = 4, b = 3;
 printf("%d", a +++b); /*it is a pre-increment*/
 return 0;

 }
  
                                                            
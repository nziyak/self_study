/* generally, while defining varying number of arguments functions, argument number is typed firstly.
to indicate argument number is varying, generally "..." is used.
in the below example argument number is varying:
   int sum(int numOfParameters, ...);

stdarg.h library meets us with 4 keywords:

1) va_list: this keyword provides us to define a pointer that points to the list that holds the varying 
number of parameters.

for example:
   va_list: parameterPtr;

2) va_start: before iterating over parameters, we need to call va_start function. that func provides us assigning the 
first parameter to parametrePtr pointer that we defined in va_list type. va_start func takes 2 parameters:
the first argument is the previously defined parameters list which is the type of va_list. and the second argument 
is the first argument the function takes. because of the first argument the sum function takes is numOfParameters,
va_start function is called like below:
   va_start(parameterPtr, numOfParameters);

3) va_arg: this function provides reading a specific type of parameter from the parameters list. the reading type can
be any type. the compiler dont find which type is the value. so we need to say it. we call the va_arg function below:
    //read an type of int parameter from the list and assign it to temporary variable.
    temp = va_arg(parameterPtr, int);

4) va_end = when our job is end up with the list that includes the function parameters we use va_end macro function. this
function cleans up the content of the pointer which iterates over the parameters we created with va_start and frees the memory:
//clean the parameters
va_end(parameterPtr);
*/

//here is an example program uses varying number of parametered sum function
#include <stdio.h>
#include <stdarg.h>

int sum(int numOfParam, ...);
double findMean(int numOfParam, ...);

int main()
{
   int num1 = 5, num2 = 10, num3 = 15;

   printf("\nnum1 = %d\nnum1 = %d\nnum1 = %d\n", num1, num2, num3);
   printf("num1 + num2 = %d\n", sum(2, num1, num2));
   printf("num1 + num2 + num3 = %d\n", sum(3, num1, num2, num3));
   
   printf("Sum(1,2,3,4,5,6,7,8,9,10) = %d\n", sum(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10));
   printf("Sum(222,333,444,555,666) = %d\n", sum(5, 222, 333, 444, 555, 666));
   
   printf("Mean(1,2,3,4,5,6,7,8,9,10) = %.3f\n", findMean(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10));
   printf("Mean(222,333,444,555,666) = %.3f\n", findMean(5, 222, 333, 444, 555, 666));

   return 0;
}

int sum(int numOfParam, ...)
{
   va_list parameterPtr;
   va_start(parameterPtr, numOfParam);

   int sum = 0;
   
   for(int i = 0; i < numOfParam; i++)
   {
      sum += va_arg(parameterPtr, int);
   }

   va_end(parameterPtr);
   return sum;
}

double findMean(int numOfParam, ...)
{
   va_list parameterPtr;
   va_start(parameterPtr, numOfParam);

   int sum = 0;
   
   for(int i = 0; i < numOfParam; i++)
   {
      sum += va_arg(parameterPtr, int); 
   }

   va_end(parameterPtr);
   return (double) sum / numOfParam;
}
//https://www.youtube.com/watch?v=gF7wjwM9Jjs&list=PLBlnK6fEyqRggZZgYpPMUxdY1CYkZtARR&index=62

#include <stdio.h>

int main()
{
    int m=30, n=20, sum;
    sum = add(m,n); //while calling a function you shouldnt mention the return type of function and the data type of the arguments
    printf("sum is %d", sum);

}

int add(int a, int b)
{
   
   return(a + b);

}

/*DIFFERENCE OF ARGUMENT AND PARAMETER;
PARAMETER IS A VARIABLE IN THE DECLARATION AND DEFINITION OF THE FUNCTION
ARGUMENT IS THE ACTUAL VALUE OF THE PARAMETER THAT GETS PASSED TO THE FUNCTION

PARAMETER IS ALSO CALLED AS FORMAL PARAMETER AND ARGUMENT IS ALSO CALLED AS ACTUAL PARAMETER
FOR EXAMPLE, IN THE CODE ABOVE, M AND N ARE ACTUAL PARAMETERS/ARGUMENTS.
BUT A AND B ARE PARAMETER/FORMAL PARAMETERS */
#include <stdio.h>

int sum(int, int);
int subtract(int, int);
int multiply(int, int);
int modulus(int, int);
int calculate(int (*)(int, int), int, int);

int main()
{
    int num1, num2;

    printf("please enter two numbers with a space between them: ");
    scanf("%d %d", &num1, &num2);

    printf("sum of the numbers you entered: %d\n", calculate(sum, num1, num2));
    printf("subtraction of the numbers you entered: %d\n", calculate(subtract, num1, num2));
    printf("multiplication of the numbers you entered: %d\n", calculate(multiply, num1, num2));
    printf("modulus of the number 1 of number 2 you entered: %d\n", calculate(modulus, num1, num2));
    
    return 0;
}

int sum(int num1, int num2)
{
    return num1 + num2;
}

int subtract(int num1, int num2)
{
    return num1 - num2;
}

int multiply(int num1, int num2)
{
    return num1 * num2;
}

int modulus(int num1, int num2)
{
    return num1 - num2;
}

int calculate(int (*operationPtr)(int, int), int num1, int num2)
{
    int result;

    result = operationPtr(num1, num2);

    return result;
}
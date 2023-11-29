#include <stdio.h>
#include <time.h>
#define N 25

long long int factorial(long long int n);

int main()
{
    long long int result;
    
    result = factorial(N);

    printf("result: %lld\n", result);
    
     return 0;
}

long long int factorial(long long int n)
{
    long long int result;
    
    if(n == 0) result = 1;

    else result = n * factorial(n-1);

    return result;
}
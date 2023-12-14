#include <stdio.h>
#include<stdlib.h>

int main()
{
    int* grades;

    if(!((grades = (int*)malloc(5 * sizeof(int))) == NULL))
    {
        printf("failed to allocate grades array\n");
        return 0;
    }
}
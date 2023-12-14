#include <stdio.h>

int main()
{
    int movieCounter;

lab:
    printf("how many movies do you want to add? ");
    scanf("%d", &movieCounter);

    if(movieCounter < 0) goto lab;
}
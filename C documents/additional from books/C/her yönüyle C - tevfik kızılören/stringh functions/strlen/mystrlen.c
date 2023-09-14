#include <stdio.h>
#include <string.h>

int mystrlen(char *s);

int main()
{
    char userName[20];
    unsigned long numOfChars = 0;

    printf("enter your username: ");
    scanf("%s", userName);

    numOfChars = mystrlen(userName);

    printf("your username is %d characters long.\n", numOfChars);

    if(numOfChars < 6)
        printf("username must be at least 6 characters long!");

    else
        printf("your username is valid");

    return 0;    
}    

int mystrlen(char *s)
{
    int i = 0;

    while(*s++ != '\0')
    {
        i++;
    }

    return i;
}
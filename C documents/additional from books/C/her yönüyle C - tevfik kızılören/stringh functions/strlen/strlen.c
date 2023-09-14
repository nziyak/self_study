/*
    strlen counts how many characters a string contains.
    it does not count NULL.
    returns a number which is a type of unsigned long.

    its prototype: size_t strlen(const char *s);

    here is an example program below:
*/

#include <stdio.h>
#include <string.h>

int mystrlen(char *s);

int main()
{
    char userName[20];
    unsigned long numOfChars = 0;

    printf("enter your username: ");
    scanf("%s", userName);

    numOfChars = strlen(userName);

    printf("your username is %d characters long.\n", numOfChars);

    if(numOfChars < 6)
        printf("username must be at least 6 characters long!");

    else
        printf("your username is valid");

    return 0;    
}    
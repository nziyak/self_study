/*
    strcpy copies the content of the string passed to it secondly to the firstly passed string.
    its prototype: char *strcpy(char* s1, const char *s2);
    an example program is below:
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char mygreeting[20] = "hello";
    char yourgreeting[20];

    //lets copy my greeting to yours
    strcpy(yourgreeting, mygreeting);

    //lets print both strings
    printf("my greeting: %s\n", mygreeting);
    printf("your greeting: %s", yourgreeting);

    return 0;
}
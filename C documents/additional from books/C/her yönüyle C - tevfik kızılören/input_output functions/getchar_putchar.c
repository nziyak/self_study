/* getchar uses buffer (klavye arabelleği). this function does not have any parameters.
every time you call it it takes the first character user entered and returns it. because of getchar is a function
that uses buffer, it waits for the user to hit the "enter" button.

here is an example of how to use getchar:
*/

#include <stdio.h>

int main()
{
    char ch;
    
    //read a character from keyboard and wait for the hitting to enter
    printf("enter a character and hit the enter button: ");
    ch = getchar();

    printf("the character you entered: ");
    putchar(ch);

    //putchar(10); provides a new line.
    putchar(10);

    return 0;
}
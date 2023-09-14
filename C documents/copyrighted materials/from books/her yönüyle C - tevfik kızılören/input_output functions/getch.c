// getch function is one of the functions that does not use the buffer.
// getch returns the entered character without waiting the hitting to enter key.
// this function does not prints the entered character
#include <stdio.h>
//#include <conio.h>

int main()
{
    char ch;
    ch = getch();

    printf("the character you entered: %c\nthe program is terminated\n", ch);

    return 0;
}

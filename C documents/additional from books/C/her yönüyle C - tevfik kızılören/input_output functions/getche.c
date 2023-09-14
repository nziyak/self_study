// also the getche function does not use the buffer. it differs from getchar with its that feature.
// its difference from getch is that getche is able to show/print the entered character.
#include <stdio.h>

int main()
{
    char ch;
    ch = getche();
    
    printf("\nthe character you entered: %c\nthe program is terminated\n", ch);

    return 0;
}
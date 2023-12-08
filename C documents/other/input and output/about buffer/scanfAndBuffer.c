#include <stdio.h>

int main()
{
    char fkey, skey;

    printf("Type in a character: ");
    scanf("%c", &fkey);
    printf("the key just accepted is %d\n", fkey);
    printf("Type in another character: ");
    scanf("%c", &skey);
    printf("the key just accepted is %d\n", skey);

    /*
        after entering the first character, user types in the enter key, too.
        that means, in the buffer, after the first entered character, there is a \n character.
        and because of the scanf function reads from buffer, before user enters a second character,
        scanf will take the \n character as the second input into skey.
        and second printf prints the ascii correspondence of \n character, which is 10.
    */

    return 0;
}
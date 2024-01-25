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

        you can use "fflush(stdin)" expression after taking string with scanf to clean buffer. (it is in the string.h lib)

        or you can also use "char c;
                             while ((c = getchar()) != '\n' && c != EOF);" 

        or you can also use fgets function instead of scanf:
            fgets(word1, sizeof(word1), stdin); //takes size of word1 bytes of input from standart input(keyboard) to word1 string
            word1[strcspn(word1, "\n")] = '\0'; //replaces \n with \0 character. (a null char is required at the end of strings)

        
    */

    return 0;
}
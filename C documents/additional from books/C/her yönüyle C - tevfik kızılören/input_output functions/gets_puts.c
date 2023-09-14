/*

    the puts function prints the string passed to it as an argument.
    and the gets function copies the string which user gave to string variable passed to it as an argument 

    here is an example usage of both:

*/

#include <stdio.h>

int main()
{
    char word[10];

    //puts function is similar to printf
    puts("enter a word: ");

    //read a word from user and copy it to string named word
    gets(word);

    puts("the word you entered is below:");
    puts(word);

    return 0;
}
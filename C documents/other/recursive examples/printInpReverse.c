#include <stdio.h>
#define WORDSIZE 10

void reverseInpWords(int num);

int main()
{
    int num = 5;

    reverseInpWords(num);

    return 0;
}

void reverseInpWords(int num)
{
    char word[WORDSIZE];

    if(num <= 1)
    {
        scanf("%s", word);
        printf("%s\n", word);
    }

    else
    {
        scanf("%s", word);
        reverseInpWords(num-1);
        printf("%s\n", word);
    }
}
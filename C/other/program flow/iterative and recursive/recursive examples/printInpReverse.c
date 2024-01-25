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

//lets say we give input 
//bit 
//and 
//bytes

//program will be run like that:

//call reverseInpWords with n equal to 3
//  scan the first word "bits" into word
//  call reverseInpWords with n equal to 2
//      scan the second word "and" into word
//      call reverseInpWords with n equal to 1
//          scan the third word "bytes" into word
//          display the ghird word "bytes"
//          return from third call
//      display the second word "and"
//      return the first word "bits"
//  display the first word "bits"
//  return from original call
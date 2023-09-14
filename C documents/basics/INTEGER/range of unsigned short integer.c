#include <stdio.h>
#include <limits.h>
       int main(){

        short unsigned int var1 = 0;          /*both of short unsigned and unsigned short are available*/
        short unsigned int var2 = USHRT_MAX;

        printf("range of short unsigned integer from: %u to %u", var1,var2);  /*%d is used to print decimal but %u is used to print unsigned decimal value*/
        return 0;                   /*you can use %ld instead of %d in printf part of the long integer and of the unsigned long integer, you should use %lu*/
       }                            /*and %lld is to print long long integer. %llu is to print unsigned long long integer*/
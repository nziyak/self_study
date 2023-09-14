#include <stdio.h>
#include <limits.h>
       int main(){

        short int var1 = SHRT_MIN;
        short int var2 = SHRT_MAX;

        printf("range of short integer from: %d to %d", var1,var2);  /*%d is used to print decimal but %u is used to print unsigned decimal value*/
        return 0;
       }
       #include <stdio.h>
       #include <limits.h>
       int main(){

        unsigned int var1 = 0;
        unsigned int var2 = UINT_MAX;

        printf("range of unsigned integer from: %u to %u", var1,var2);  /*%d is used to print decimal but %u is used to print unsigned decimal value*/
        return 0;
       }
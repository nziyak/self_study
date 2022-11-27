#include <stdio.h>

int main(){

    printf("%d", sizeof(long));

    return 0;

    /*sizeof(short)<=sizeof(int)<=sizeof(long)*/
    /*<= means less than or equals to*/

    /*signed int is equal to int*/
    
    /* int some_variable_name; is signed integer variable
       Unsigned int some_variable_name; allows only positive values */


    /* #include <stdio.h>
       #include <limits.h>
       int main(){

        int var1 = INT_MIN;
        int var2 = INT_MAX;

        printf("range of signed integer from: %d to %d", var1,var2);
        return 0;

      }*/   





}
/*

int fun(int,char);     you dont have to write names of the parameters in function declaration. 
                       but you should mention their data types. and, you have to mention names of parameters in function definiton
                       
*/

#include <stdio.h>


char func();
int main(){
    

    char c = func();
    printf("character c is : %c", c);
}

char func(){
    
    return 'k';
}
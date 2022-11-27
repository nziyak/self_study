#include <stdio.h>
int i, j, number;
int main(){

printf("pls give a number");
scanf("%d", &number);

    for(i=2; i<number;i++){

        if(number%i==0){
            printf("this number is composite number");
            break;
        }
        else{
            printf("this is prime");
            break;
        }
       

     }



}
/* #include <stdio.h>
int main(){

int n;

printf("Enter a number\n", &n);
scanf("%d",&n);

while(n!=0)
{
  if(n<0){
    break;
    }

  printf("Enter a number\n", &n);
  scanf("%d",&n);
}

printf("you entered an invalid value. please try again.\n");
printf("Enter a number\n", &n);

}  */

#include <stdio.h>   //program to print all odd numbers from 1 to 20
int main(){

int i, n = 2;
for(i=1 ; i<=20 ; i++)
{
    if(i==n){
        n = n+2;
        continue;
    }
    printf("%d", i);
}



}
#include <stdio.h>

int main(){
int a = 4, b = 3;   //3 0011 4 0100

a = a ^ b;
b = a ^ b;
a = a ^ b;

printf("after XOR,a = %d and b = %d", a,b);
return 0;

}
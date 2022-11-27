/*#include <stdio.h>
int main(){
int i = 3;
while(i>0)
{
    printf("i");
    i--;
}
} */


// for(initialization;condition;increment/decrement) so the for equivalent of the code above is;

#include <stdio.h>
int main(){
int i;  
for(i = 3; i > 0; i--)
{
    printf("i");
}
}
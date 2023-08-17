#include <stdio.h>

int main(){

int i = 0;
while(i>0)
{
  printf("%d", i);
  i--;
}
}
// the code above is a while loop.-it has not a output because 0 is not greater than 0.- now, the do-while loop;
#include <stdio.h>

int main(){

int i = 0;
do
{
  printf("%d", i);
  i--;
}
while(i>0);
}

//that code means, first evaulate the printf and decrement operation, then check the condition(i>0)
//as -1 is not greater than 0, we come out of this loop, hence the output is zero




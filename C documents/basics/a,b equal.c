#include <stdio.h>
#define equal(a,b) if (a == b) \
                           printf("%d is equal to %d", a, b); \
                            


int main(){

equal(5,6);
return 0;
}

#define greater(a,b) if (a > b) \
                           printf("%d is greater than %d", a, b); \
                    else \
                           printf("%d is greater than %d", b, a);  \

int k(){

greater(5,6);
return 0;
}                           


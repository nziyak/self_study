/*#include <stdio.h>
#define PI 3.146758          /*#define NAME value. job of preprocessor -not compiler- is replace the NAME with value.
           BE CAREFUL!DONT PUT ; AT THE END OF DEFINING LINE OF CONSTANT*/

/*int main(){

printf("%.6f",PI);
return 0;


} */

/*#include <stdio.h>
#define add(x,y) x+y

int main(){

printf("addition of two numbers:%d", add(998,665));
return 0;

} */

/*#include <stdio.h>
#define greater(a,b) if (a > b) \
                           printf("%d is greater than %d", a, b); \
                     else \
                           printf("%d is greater than %d", b, a);      
int main(){

greater(5,5);
return 0;
} */

/*#include <stdio.h>
#define add(x,y) x+y

int main(){

printf("result of expression a*b+c is: %d", 5 * add(5,6)); /*it will take it like "5*5+6" if u want to 
                                                           first add 5 and 6 then multiply the result by 5, u should
                                                           write like " 5 * (add(5,6))"  */

#include <stdio.h>


int main(){

printf("Date:%s\n", __DATE__ );
printf("Time:%s", __TIME__ );
return 0;
}



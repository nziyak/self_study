#include <stdio.h>

/*int x = 9;
                 // you are not allowed to duplicate the cases
int main(){ 
switch(x)
{
    case 1: printf("x is 1");
            break;
    case 2: printf("x is 2");
            break;
    case 3: printf("x is 3");
            break;        
    default: printf("e hicbiri degilmis o zamaan");
            break;

}
} */

/*#include <stdio.h>
int main(){
int a=1, b=2, c=3;
switch(a*b+c)
{
    case 1: printf("choice 1");
            break;
    case 5: printf("choice 2");
            break;
    default: printf("default");
            break;                
}

} */

/*#include <stdio.h>
int main(){

int a=9;

if (a==3){

    printf("a is 3");
}
else if (a==17){
    printf("a is 17");
}

if(a==9){

    if(9+3==12){
        printf("succesful process!");
    }
    else{
        printf("sorry you have to study calculus 001");


    }
}
} */

//variable expressions and floats are not allowed in case labels
// MACROs are allowed in case labels. (remember the MACROs are declared in that way: #define PI 3.14)
// default can be placed anywhere inside switch. but it will be evaulated after all cases are checked.
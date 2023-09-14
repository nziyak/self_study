#include <stdio.h>
int main(){

    int a;
    a = fun1()+fun2(); //it is not defined whether fun1() is called first or fun2() is called first. it depends on the compiler
    printf("%d", a);
    return 0;
}

int fun1(){
printf("Nuri Ziya");
return 4;

}

int fun2(){
printf(" KIRTEPE");
return 9;

}
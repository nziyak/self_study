#include <stdio.h>
int i, n=5, r=4, x, factorial = 1;
int fact(int);


int main(){

    
    printf("combination of(%d,%d) is %d!/((%d-%d)!*%d!)", n, r, fact(n), n, r, fact(r));
    
}

int fact(int x){
        
        

        for(i=1; i<=x; i++){
            factorial=factorial*i;
        }
        return factorial;
    }
/* #include <stdio.h>
int main(){
    int i;
    int j;

    for(i=1; i<=2; i++){
        
        for(j=1; j<=2; j++){
            printf("*");
        }
    
    }
} */

#include <stdio.h>
int main(){
    int i, n , j;
    printf("How many rows you want in your pyramid?\n");
    scanf("%d", &n);

    for(i=1; i<=n; i++){

        for(j=1; j<=2*n-1; j++){

            if(j >= n-(i-1) && j <= n+(i-1)){
                printf("*");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
  return 0;
}

//https://www.youtube.com/watch?v=SQCPZYAXoZs&list=PLBlnK6fEyqRggZZgYpPMUxdY1CYkZtARR&index=42

#include <stdio.h>
int main(){
    int i = 1024;
    for(; i; i>>=1) //you can skip steps in for but you have to mention steps by using ;
    {                //condition checking step always produce the answer true or false
        printf("Hello World\n");
            
    }
    return 0;
    
}
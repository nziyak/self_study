#include <stdio.h>
//#include <math.h>


void finput(int sel); // function will take the input
int gcdCal(int num1, int num2); // gcd calculator function
int lcmCal(int num1, int num2); // lcm calculator function
float calculate_mean();
float stdDevCal();


int main()
{
    int sel; // menu selection variable

    printf("Welcome! Please select an operation\n");
    printf("1) GCD Calculator\n");
    printf("2) LCM Calculator\n");
    printf("3) Standard Deviation Calculator\n");
    printf("4) Exit\n----------------------\n");

    scanf("%d", &sel);

    switch(sel)
    {
        case 1:
            
            finput(1);
            break;
        
        case 2:
            
            finput(2);
            break;
        
        case 3:
            
            finput(3);
            break;
        
        case 4:
            return 0;    
    }

    return 0;
}

void finput(int sel)
{
    int num1, num2;
    
    switch(sel)
    {
        case 1:
            
            printf("\nplease enter two different numbers\n");
            
            printf("number 1: ");
            scanf("%d", &num1);
            
            printf("number 2: ");
            scanf("%d", &num2);

            printf("%d %d", num1, num2);    
           
            printf("\nGCD of these two numbers: %d\n", gcdCal(num1, num2));

            break;

        case 2:
        
            printf("\nplease enter two different numbers\n");
            
            printf("number 1: ");
            scanf("%d", &num1);
            
            printf("number 2: ");
            scanf("%d", &num2);

            printf("%d %d", num1, num2);    
            
            printf("\nLCM of these two numbers: %d\n", lcmCal(num1, num2));

            break;

        case 3:
    }
}

int gcdCal(int num1, int num2)
{
    FILE *writer;
    int gcd;
    
    for(int i = 1; i <= num1 && i <= num2; i++)
    {
        if((num1 % i == 0) && (num2 % i == 0))
            gcd = i; 
    }

    writer = fopen("result.txt", "a");

    fprintf(writer, "%d ", gcd);    

    fclose(writer);

    return gcd;
}

int lcmCal(int num1, int num2)
{
    FILE *writer;
    int lcm;
    
    lcm = (num1 * num2) / gcdCal(num1, num2);

    writer = fopen("result.txt", "a");

    fprintf(writer, "%d ", lcm);    

    fclose(writer);

    return lcm;
}
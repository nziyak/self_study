/*
    sprintf is a version of printf. 
    while printf prints the parameters we gave it to console, sprintf prints them to a string.

    here is an example of printf and sprintf usage below:
*/

#include <stdio.h>

/*
    int main()
    {
        int num1 = 5, num2 = 10;
        char stringke[50];

        //normal printf usage: prints to console
        printf("\n%d x %d = %d\n", num1, num2, num1*num2);

        //sprintf prints to stringke, not to console
        sprintf(stringke, "%d x %d = %d\n", num1, num2, num1*num2);

        printf("\nthe string that sprintf created:\n");
        printf(stringke);
        printf("\n");

        return 0;
    }
*/

int main()
{
    char cities[50] = "Ankara Kars Antalya";
    char city1[3], city2[20], city3[20];

    //lets read each city formatted
    sscanf(cities, "%s %s %s", city1, city2, city3);

    printf("the first city: %s\n", city1);
    printf("the second city: %s\n", city2);
    printf("the third city: %s\n", city3);

    return 0;
}
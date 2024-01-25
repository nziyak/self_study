#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char name[10],
         color[10];
    double weight;
}ball;

int main()
{
    ball* balls;
    int numOfBalls;

    printf("how many balls do you have? ");
    scanf("%d", &numOfBalls);
    printf("\n");

    balls = calloc(numOfBalls, sizeof(ball));

    for(int i = 0; i < numOfBalls; i++, balls += sizeof(ball))
    {
        /*printf("enter the name of the ball%d: ", i);
        scanf("%s", (balls + (i * sizeof(ball)))->name);
        printf("\n");

        printf("enter the color of the ball%d: ", i);
        scanf("%s", (balls + (i * sizeof(ball)))->color);
        printf("\n");

        printf("enter the weight of the ball%d: ", i);
        scanf("%lf", &(balls + (i * sizeof(ball)))->weight);
        printf("\n");*/
        
        printf("enter the name of the ball%d: ", i);
        scanf("%s", balls->name);
        printf("\n");

        printf("enter the color of the ball%d: ", i);
        scanf("%s", balls->color);
        printf("\n");

        printf("enter the weight of the ball%d: ", i);
        scanf("%lf", &balls->weight);
        printf("\n");
    }

    balls -= numOfBalls * sizeof(ball);

    for(int i = 0; i < numOfBalls; i++, balls += sizeof(ball))
    {
        printf("name of the ball%d: %s\n", i, balls->name);
        printf("color of the ball%d: %s\n", i, balls->color);
        printf("weight of the ball%d: %lf\n", i, balls->weight);
    }

    free(balls);

    return 0;
}
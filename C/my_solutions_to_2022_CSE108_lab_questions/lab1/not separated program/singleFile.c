#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14

int* midpoint(int x1, int y1, int x2, int y2, int* pts);
double slopeCal(int x1, int y1, int x2, int y2);
double mySqrt(double num);
double areaCal(int x1, int y1, int* pts);

int main()
{
    int x1, y1, x2, y2;

    printf("please give the coordinates of the first point: ");
    scanf("%d %d", &x1, &y1);
    
    printf("please give the coordinates of the second point: ");
    scanf("%d %d", &x2, &y2);

    int* pts = (int*)malloc(2 * sizeof(int));

    midpoint(x1, y1, x2, y2, pts);

    printf("coordinates of the midpoint: %d, %d\n", *pts, *(pts+1));

    double slope = slopeCal(x1, y1, x2, y2);

    printf("slope: %lf\n", slope);

    double area = areaCal(x1, y1, pts);

    printf("area of the circle: %lf\n", area);

    free(pts);
    
    return 0;
}

int* midpoint(int x1, int y1, int x2, int y2, int* pts)
{
    int mpx = (x1 + x2) / 2; // x coordinate of the midpoint is the midpoint of x coordinates of two points
    int mpy = (y1 + y2) / 2; // same for y coordinate of midpoint
    
    pts[0] = mpx; 
    pts[1] = mpy;

    return pts;
}

double slopeCal(int x1, int y1, int x2, int y2)
{
    double slope = (y2 - y1) / (x2 - x1);
    
    return slope;
}

double mySqrt(double num) 
{
    if(num == 0) 
        return 0;
    
    double prediction = 1; // we make our first prediction as 1
    double error = 0.00001; // defining the acceptable error
    
    while(1) 
    {
        double new_prediction = 0.5 * (prediction + num / prediction); // calculate the new prediction using Newton - Ralph method
        
        double check = new_prediction - prediction;

        if(check < 0)
            check = -check;
        
        if(check < error) // Check the error
            return new_prediction;
        
        prediction = new_prediction; // Loop again with the new prediction
    }
}

double areaCal(int x1, int y1, int* pts)
{
    double toBeSqrt = (x1 - *pts) * (x1 - *pts) + (y1 - *(pts+1)) * (y1 - *(pts+1));

    double radius = mySqrt(toBeSqrt);
        
    double area = PI * radius * radius; 

    return area;
}
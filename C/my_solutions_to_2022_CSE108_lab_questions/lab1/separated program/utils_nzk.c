#include "utils_nzk.h"

int* midpoint(int x1, int y1, int x2, int y2, int* pts)
{
    int mpx = (x1 + x2) / 2;
    int mpy = (y1 + y2) / 2;
    
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
        
        if(fabs(new_prediction - prediction) < error) // Check the error
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
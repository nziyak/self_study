#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int x1, y1, x2, y2;

    printf("please give the coordinates of the first point: ");
    scanf("%d %d", &x1, &y1);
    
    printf("please give the coordinates of the second point: ");
    scanf("%d %d", &x2, &y2);

    int* pts = (int*)malloc(2 * sizeof(int));

    midpoint(x1, y1, x2, y2, pts);

    printf("coordinates of the midpoint: %d, %d", *pts, *(pts+1));

    double slope = slopeCal(x1, y1, x2, y2);

    printf("slope: %lf\n", slope);

    double area = areaCal(x1, y1, pts);

    printf("area of the circle: %lf\n", area);

    free(pts);
    
    return 0;
}
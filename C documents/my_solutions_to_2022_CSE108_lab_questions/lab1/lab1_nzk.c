#include <stdio.h>

int* midpoint(int x1, int y1, int x2, int y2);

int main()
{
    int x1, y1, x2, y2;

    printf("please give the coordinates of the first point: ");
    scanf("%d %d", &x1, &y1);
    
    printf("please give the coordinates of the second point: ");
    scanf("%d %d", &x2, &y2);

    int* pts = midpoint(x1, y1, x2, y2);

    printf("coordinates of the midpoint: %d, %d", *pts, *(pts+1));

    return 0;
}
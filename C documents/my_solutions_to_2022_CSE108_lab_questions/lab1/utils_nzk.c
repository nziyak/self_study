#include "utils_nzk.h"

int* midpoint(int x1, int y1, int x2, int y2)
{
    int mpx = (x1 + x2) / 2;
    int mpy = (y1 + y2) / 2;
    
    int pts[2] = {mpx,mpy};

    return pts;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct a{
    int a;
    struct a* ptr;
}try;

try* f();

int main()
{
    try* mainPtr = f();
    printf("%d", mainPtr->a);
}

try* f()
{
    try* m = (try*)malloc(sizeof(try)); //wont be destroyed?
    m->a = 5;
    return m;
}
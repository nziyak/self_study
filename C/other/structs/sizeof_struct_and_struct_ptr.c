#include <stdio.h>
#pragma pack(1)

typedef struct m{
    char a;
    int b;
    char c;
}s;

int main()
{
    s st;

    printf("sizeof struct: %d\n", sizeof(st));
}
#include <stdio.h>

union u{
    int a, b;
};

int main()
{
    union u u1;

    u1.a = 5;
    u1.b = 4;

    printf("%d", u1.a+u1.b);
}
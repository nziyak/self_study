#include <stdio.h>

int check(void);

int main()
{
    int a = check();
    printf("%d\n", a);
    return 0;
}

int check(void)
{
    return (2==3);
}
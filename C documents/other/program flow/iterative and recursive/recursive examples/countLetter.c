#include <stdio.h>

int count(char ch, const char* str);

int main()
{
    char str[10] = "missisipi";
    char ch = 's';

    printf("%c occurs %d times.\n", ch, count(ch, str));

    return 0;
}

int count(char ch, const char* str)
{
    int ans;

    if (str[0] == '\0')  ans = 0;

    else
    {
        if (ch == str[0])  ans = 1 + count(ch, &str[1]);
        else  ans = count(ch, &str[1]);
    }

    return ans; 
}
//输出斐波那契数列第n项的值
//1 1 2 3 5 8 13 21 34 55 89...
#include <stdio.h>

int func(int n);

int main()
{
    printf("%d",func(10));

    return 0;
}

int func(int n)
{
    if(n == 1 || n == 2)
    {
        return 1;
    }
    else if(n > 2)
    {
        return func(n - 1) + func(n - 2);
    }
}

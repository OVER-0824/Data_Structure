//计算1到100的和，使用递归的方式
#include <stdio.h>

int func(int n);

int main()
{
    printf("%d",func(100));

    return 0;
}

int func(int n)
{
    if(n == 1)
    {
        return 1;
    }
    return func(n - 1) + n;
}

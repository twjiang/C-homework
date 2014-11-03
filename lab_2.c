/*This Code is Submitted by 姜天文 for Problem 1004 at 2012-12-31 09:23:32*/
#include <stdio.h>
#include <stdlib.h>
int  structrue_of_plalindrome(int a, int b);
int prime_judeging(int n);
int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    structrue_of_plalindrome(a, b);
    return 0;
}

int structrue_of_plalindrome(int n, int m)//根据给定区间构造回文数
{
    int a, b, c, d, e, f;
    for(e = 0; e < 10; e++)
    {
        for(d = 0; d < 10; d++)
        {
            for(c = 0; c < 10; c++)
            {
                for(b = 0; b < 10; b++)
                {
                    for(a = 0; a < 10; a++)
                    {
                        f = e*100000000 + d*10000000 + c*1000000 + b*100000 + a*10000 + b*1000 + c*100 + d*10 + e;

                        while(f % 10 == 0 && f > 10)
                            f = f/10;
                        if(f > m)
                            return 0;
                        if(f == 9 && n <= 11)
                            printf("11\n");
                        if(prime_judeging(f) && f >= n )
                            printf("%d\n", f);
                    }
                }
            }
        }
    }
    return 0;
}

int prime_judeging(int n)//判断是否为质数
{
    int i;
    for(i = 2; i*i <= n; i++)
    {
        if(n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

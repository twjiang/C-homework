/* Code by Slyar */
#include <stdio.h>
#include <stdlib.h>

#define max 8
void contrast(); /* 对比92种方法*/
int check(int n); /* 检查当前列能否放置皇后 */
void place(int n); /* 尝试皇后位置,n为横坐标 */
void transforming(char a[][max]);//将二维数组转化成一维
int judging(char a[][max]);//判断此时棋盘是否已成定局
int QUEEN[max]={-1,-1,-1,-1,-1,-1,-1,-1},count=0;
int queen[max];

int main()
{
    int i,j,re;
    char a[max][max]={{0},{0}};
    //输入初始棋盘
    for(i=0;i<max;i++)
    {
        for(j=0;j<max;j++)
        {
            scanf("%c",&a[i][j]);
        }
        getchar();
    }
    //判断此时棋盘是否已成定局
    re=judging(a);
    if(re==0)
    {
        printf("0\n");
        return 0;
    }
    transforming(a);
    place(0); /* 从横坐标为0开始依次尝试 */
    printf("%d\n", count);
    return 0;
}
void contrast() /* 对比92种方法 */
{
    int i,flag=1;
    for(i=0;i<max;i++)
    {
        if(QUEEN[i]!=-1)
        {
            if(QUEEN[i]!=queen[i])
            {
                flag=0;
            }
        }
    }
    if(flag==1)
        count++;
}

int check(int n) /* 检查当前列能否放置皇后 */
{
    int i;
    for(i = 0; i < n; i++) /* 检查横排和对角线上是否可以放置皇后 */
    {
        if(queen[i] == queen[n] || abs(queen[n] - queen[i]) == (n - i))
        {
            return 0;
        }
    }
    return 1;
}

void place(int n) /* 尝试皇后位置,n为横坐标 */
{
    int i;
    for(i = 0; i < max; i++)
    {
        queen[n] = i; /* 将皇后摆到当前循环到的位置 */
        if(check(n))
        {
            if(n == max - 1)
            {
                contrast(); /* 如果全部摆好，则输出所有皇后的坐标 */
            }
            else
            {
                place(n + 1); /* 否则继续摆放下一个皇后 */
            }
        }
    }
}
int judging(char a[][max])//判断此时棋盘是否已成定局
{
    int i,j,k;
    for(i=0;i<max;i++)
    {
        for(j=0;j<max;j++)
        {
            if(a[i][j]=='*')
            {
                if(i!=j)
                {
                    for(k=0;k<max;k++)
                    {
                        if(k!=i&&a[k][j]=='*')
                            return 0;
                        if(k!=j&&a[i][k]=='*')
                            return 0;
                    }
                }
                else
                {
                    for(k=0;k<max;k++)
                    {
                        if(k!=i&&k!=j&&(a[k][j]=='*'||a[i][k]=='*'))
                            return 0;
                    }
                }
                for(k=1;i+k<max&&j-k>=0;k++)
                {
                    if(a[i+k][j-k]=='*')
                        return 0;
                }
                for(k=1;i+k<max&&j+k<max;k++)
                {
                    if(a[i+k][j+k]=='*')
                        return 0;
                }
            }
        }
    }
    return 1;
}
void transforming(char a[][max])//将二维数组转化成一维
{
    int x,y;
    for(x=0;x<max;x++)
    {
        for(y=0;y<max;y++)
        {
            if(a[x][y]=='*')
                QUEEN[y]=x;
        }
    }
}


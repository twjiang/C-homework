/*This Code is Submitted by ½ªÌìÎÄ for Problem 1533 at 2012-11-03 11:13:16*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int i,j,r=0;
    while(scanf("%d",&n)==1)
    {
        r=0;
        int num[3][1000]={{1},{1},{0}};
        if(n<3)
        {
            printf("1");
            printf("\n");
            continue;
        }
        else
        {
            for(i=2;i<=n-1;i++)
            {
                for(j=0;j<1000;j++)
                {
                    num[2][j]=(r+num[1][j]+num[0][j])%10;
                    r=(r+num[1][j]+num[0][j])/10;
                    num[0][j]=num[1][j];
                    num[1][j]=num[2][j];
                }
            }
            i=999;
            while(num[2][i]==0)
            {
                i--;
            }
            for(j=i;j>=0;j--)
            {
                printf("%d",num[2][j]);
            }
            printf("\n");
        }
    }
    return 0;
}


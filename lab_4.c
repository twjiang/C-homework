#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000
int RecursiveFunction(int n,int m);


int main()
{
    int n,m,y;
   while(scanf("%d %d",&n,&m)==2)
   {
        if(n==0&&m==0)
            break;
        else if(n<0)
            y=(n%m+m)%m;
        else
            y=RecursiveFunction(n,m);
        printf("%d\n",y);
    }
    return 0;
}

int RecursiveFunction(int n,int m)
{
    int a[4]={1,2,3,0},y,i,f;
    if(n<=3)
    {
        f=n;
        y=f%m;
    }
    else
    {
        for(i=3;i<n;i++)
        {
            a[0]=a[0]%m;
            a[1]=a[1]%m;
            a[2]=a[2]%m;
            a[3]=a[2]+a[0];
            a[3]=a[3]%m;
            a[0]=a[1];
            a[1]=a[2];
            a[2]=a[3];
        }
        y=a[3];
    }
    return y;
}




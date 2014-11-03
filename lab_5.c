#include <stdio.h>
#include <stdlib.h>

int isAnagram(const char * const s1,const char * const s2);

int main()
{
    char s1[60]={"\0"},s2[60]={"\0"};
    int re;
    while(scanf("%s %s",s1,s2)==2)
    {
        re=isAnagram(s1,s2);
        if(re==0)
            printf("No\n");
        if(re==1)
            printf("Yes\n");
    }
    return 0;
}
int isAnagram(const char * const s1,const char * const s2)
{
    int i,j,flag1=0,flag2=0;
    int sum1=0,sum2=0;
    int a[60],b[60];
    for(i=0,j=0;s1[i]!=0;i++)
    {
        if(s1[i]!=95)
        {
            a[j]=s1[i];
            j++;
        }
    }
    a[j]=0;
    for(i=0,j=0;s2[i]!=0;i++)
    {
        if(s2[i]!=95)
        {
            b[j]=s2[i];
            j++;
        }
    }
    b[j]=0;
    for(i=0;a[i]!=0;i++)//判断是否相同
    {
        if((a[i]-b[i])%32==0)
            flag1++;
    }
    if(flag1==i)
        return 0;
    for(i=0;s1[i]!=0;i++)//计算各单词字母部分ASCII的和
    {
        if(s1[i]==95)
            continue;
        sum1=sum1+s1[i];
    }
    for(i=0;s2[i]!=0;i++)
    {
        if(s2[i]==95)
            continue;
        sum2=sum2+s2[i];
    }
    if((sum1-sum2)%32!=0)//比较两单词字母部分的ASCII的和
        return 0;
    for(i=0;s1[i]!=0;i++)
    {
        for(j=0;s2[j]!=0;j++)
        {
            if(s1[i]==s2[j]||s1[i]==s2[j]+32||s1[i]==s2[j]-32)
               flag2=1;
        }
        if(flag2!=1)
            return 0;
    }
    return 1;
}

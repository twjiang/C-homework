#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int sam_straight_number();//判断有三个相同或顺子
int judging_fir();//判断构成的14张牌是否构成“和”
int judging_sec();//判断构成的14张牌是否构成“和”
int judging_thi();//判断构成的14张牌是否构成“和”

int majiongarr[40];//详细记录各种牌型的数目

int main()
{
    int times;//用户给出题目的个数
    int n,i,j=0;
    int flag=1;
    int raight[40];//记录Tin牌所缺的牌
    char str[5];//存储每个字符串
    scanf("%d",&times);
    while(times--)
    {
      memset(majiongarr,0,sizeof(majiongarr));
      memset(raight,0,sizeof(raight));
      flag=1;
      j=0;
      for(i=0;i<13;i++)
        {
            scanf("%s",str);
            switch(str[1])//判断初始牌在majiongarr[]中的位置
            {
                case'm':
                    n=str[0]-'1';
                    break;
                case's':
                    n=str[0]-'1'+9;
                    break;
                case'p':
                    n=str[0]-'1'+18;
                    break;
                default:
                    n=str[0]-'1'+27;
            }
            majiongarr[n]++;//详细记录各种牌型的数目
        }
        for(i=0;i<34;i++)//枚举第14张可能的牌，从而判断13张是否为Tin
        {
            if(majiongarr[i]==4)//只有四副牌
                continue;
            else
            {
                majiongarr[i]++;
                if(judging_fir()||judging_sec()||judging_thi())//判断是否满足三种情况中的一种
                {
                    flag=0;
                    raight[j]=i;
                    j++;
                }

            }
            majiongarr[i]--;
        }
        if(flag)//flag未被赋值0
            printf("Nooten\n");
        else//输出“差”的那张牌
        {
            printf("%d",j);
            for(i=0;i<j;i++)//输出字母m、s、p、c
            {
                printf(" %d",(raight[i]%9)+1);
                if(raight[i]<9)
                {
                    printf("m");
                }
                if(raight[i]>=9&&raight[i]<18)
                {
                    printf("s");
                }
                if(raight[i]>=18&&raight[i]<27)
                {
                    printf("p");
                }
                if(raight[i]>=27&&raight[i]<34)
                {
                    printf("c");
                }
            }
            printf("\n");
        }
    }
    return 0;
}
int judging_fir()//判断是否为第一种情况
{
    int i;
    for(i=0;i<34;i++)
    {
        if(majiongarr[i]>=2)
        {
            majiongarr[i]=majiongarr[i]-2;
            if(sam_straight_number())//判断有三个相同或顺子
            {
                majiongarr[i]=majiongarr[i]+2;//还原数组
                return 1;
            }
            majiongarr[i]=majiongarr[i]+2;//还原数组
        }

    }
    return 0;
}
int sam_straight_number()//判断有三个相同或顺子
{
    int i,j,flag=0;
    int majtemp[40];
    for(i=0;i<34;i++)
    {
        majtemp[i]=majiongarr[i];
    }
    for(i=0;i<19;i=i+9)
    {
        for(j=0;j<9;j++)
        {
            if(majtemp[i+j]>=3)
            {
                flag++;
                majtemp[i+j]=majtemp[i+j]-3;
            }
            while(j<=6&&majtemp[i+j]&&majtemp[i+j+1]&&majtemp[i+j+2])
            {
                majtemp[i+j]--;
                majtemp[i+j+1]--;
                majtemp[i+j+2]--;
                flag++;
            }
        }
    }
    for(i=27;i<34;i++)
    {
        if(majtemp[i]>=3)
        {
            majtemp[i]=majtemp[i]-3;
            flag++;
        }
    }
    if(flag==4)
        return 1;
    else
        return 0;
}
int judging_sec()//判断是否为第二种情况
{
    int i;
    for(i=0;i<34;i++)
    {
        if(majiongarr[i]!=2&&majiongarr[i]!=0)//每种牌型个数要么为0、要么为2
            return 0;
    }
    return 1;
}
int judging_thi()//判断是否为第三种情况
{
    int i,j;
    for(i=27;i<34;i++)//保证每个汉字个数不为零
    {
        if(majiongarr[i]==0)
            return 0;
    }
    for(i=0;i<19;i=i+9)//保证数字1、9的个数不为零
    {
        if(majiongarr[i]==0||majiongarr[i+8]==0)
            return 0;
    }
    for(i=1;i<=19;i=i+9)//保证其他牌型个数为零
    {
        for(j=0;j<7;j++)
        {
            if(majiongarr[i+j]!=0)
                return 0;
        }
    }
    return 1;
}

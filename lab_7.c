#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int sam_straight_number();//�ж���������ͬ��˳��
int judging_fir();//�жϹ��ɵ�14�����Ƿ񹹳ɡ��͡�
int judging_sec();//�жϹ��ɵ�14�����Ƿ񹹳ɡ��͡�
int judging_thi();//�жϹ��ɵ�14�����Ƿ񹹳ɡ��͡�

int majiongarr[40];//��ϸ��¼�������͵���Ŀ

int main()
{
    int times;//�û�������Ŀ�ĸ���
    int n,i,j=0;
    int flag=1;
    int raight[40];//��¼Tin����ȱ����
    char str[5];//�洢ÿ���ַ���
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
            switch(str[1])//�жϳ�ʼ����majiongarr[]�е�λ��
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
            majiongarr[n]++;//��ϸ��¼�������͵���Ŀ
        }
        for(i=0;i<34;i++)//ö�ٵ�14�ſ��ܵ��ƣ��Ӷ��ж�13���Ƿ�ΪTin
        {
            if(majiongarr[i]==4)//ֻ���ĸ���
                continue;
            else
            {
                majiongarr[i]++;
                if(judging_fir()||judging_sec()||judging_thi())//�ж��Ƿ�������������е�һ��
                {
                    flag=0;
                    raight[j]=i;
                    j++;
                }

            }
            majiongarr[i]--;
        }
        if(flag)//flagδ����ֵ0
            printf("Nooten\n");
        else//��������������
        {
            printf("%d",j);
            for(i=0;i<j;i++)//�����ĸm��s��p��c
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
int judging_fir()//�ж��Ƿ�Ϊ��һ�����
{
    int i;
    for(i=0;i<34;i++)
    {
        if(majiongarr[i]>=2)
        {
            majiongarr[i]=majiongarr[i]-2;
            if(sam_straight_number())//�ж���������ͬ��˳��
            {
                majiongarr[i]=majiongarr[i]+2;//��ԭ����
                return 1;
            }
            majiongarr[i]=majiongarr[i]+2;//��ԭ����
        }

    }
    return 0;
}
int sam_straight_number()//�ж���������ͬ��˳��
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
int judging_sec()//�ж��Ƿ�Ϊ�ڶ������
{
    int i;
    for(i=0;i<34;i++)
    {
        if(majiongarr[i]!=2&&majiongarr[i]!=0)//ÿ�����͸���ҪôΪ0��ҪôΪ2
            return 0;
    }
    return 1;
}
int judging_thi()//�ж��Ƿ�Ϊ���������
{
    int i,j;
    for(i=27;i<34;i++)//��֤ÿ�����ָ�����Ϊ��
    {
        if(majiongarr[i]==0)
            return 0;
    }
    for(i=0;i<19;i=i+9)//��֤����1��9�ĸ�����Ϊ��
    {
        if(majiongarr[i]==0||majiongarr[i+8]==0)
            return 0;
    }
    for(i=1;i<=19;i=i+9)//��֤�������͸���Ϊ��
    {
        for(j=0;j<7;j++)
        {
            if(majiongarr[i+j]!=0)
                return 0;
        }
    }
    return 1;
}

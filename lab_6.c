/* Code by Slyar */
#include <stdio.h>
#include <stdlib.h>

#define max 8
void contrast(); /* �Ա�92�ַ���*/
int check(int n); /* ��鵱ǰ���ܷ���ûʺ� */
void place(int n); /* ���Իʺ�λ��,nΪ������ */
void transforming(char a[][max]);//����ά����ת����һά
int judging(char a[][max]);//�жϴ�ʱ�����Ƿ��ѳɶ���
int QUEEN[max]={-1,-1,-1,-1,-1,-1,-1,-1},count=0;
int queen[max];

int main()
{
    int i,j,re;
    char a[max][max]={{0},{0}};
    //�����ʼ����
    for(i=0;i<max;i++)
    {
        for(j=0;j<max;j++)
        {
            scanf("%c",&a[i][j]);
        }
        getchar();
    }
    //�жϴ�ʱ�����Ƿ��ѳɶ���
    re=judging(a);
    if(re==0)
    {
        printf("0\n");
        return 0;
    }
    transforming(a);
    place(0); /* �Ӻ�����Ϊ0��ʼ���γ��� */
    printf("%d\n", count);
    return 0;
}
void contrast() /* �Ա�92�ַ��� */
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

int check(int n) /* ��鵱ǰ���ܷ���ûʺ� */
{
    int i;
    for(i = 0; i < n; i++) /* �����źͶԽ������Ƿ���Է��ûʺ� */
    {
        if(queen[i] == queen[n] || abs(queen[n] - queen[i]) == (n - i))
        {
            return 0;
        }
    }
    return 1;
}

void place(int n) /* ���Իʺ�λ��,nΪ������ */
{
    int i;
    for(i = 0; i < max; i++)
    {
        queen[n] = i; /* ���ʺ�ڵ���ǰѭ������λ�� */
        if(check(n))
        {
            if(n == max - 1)
            {
                contrast(); /* ���ȫ���ںã���������лʺ������ */
            }
            else
            {
                place(n + 1); /* ��������ڷ���һ���ʺ� */
            }
        }
    }
}
int judging(char a[][max])//�жϴ�ʱ�����Ƿ��ѳɶ���
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
void transforming(char a[][max])//����ά����ת����һά
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


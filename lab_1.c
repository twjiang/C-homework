#include <stdio.h>
#include <stdlib.h>

int main()
{
    char x,y,z;
    int i,j,k,m;

    do
    {
        printf("Input a character please.\n");
        scanf(" %c",&x);
        if(x!='0')
        {
            if(x>=65&&x<=90)
            {
                for(i=1;i<=x-'A'+1;i++)
                {
                    for(j=1;j<=x-'A'+1-i;j++)
                        printf(" ");
                        printf("A");
                    for(k=1;k<=i-1;k++)
                    {
                        y='A'+k;
                        printf("%c",y);
                    }
                    for(m=i-2;m>0;m--)
                    {
                        z='A'+m;
                        printf("%c",z);
                    }
                    if(i-2>=0)
                    printf("A");
                    printf("\n");

                }
            }
            else if(x!='0')
            {
                printf("Invalid character!\n");

            }
            else
            break;
        }
        else
        break;
    }while(x!='0');

     return 0;
}






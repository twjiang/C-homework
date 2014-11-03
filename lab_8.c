#include <stdio.h>
#include <stdlib.h>
#define N 128
int main()
{
    int i,cont=1;
    char str[N];
    while(scanf("%s",str)==1)
    {
        for(i=0;str[i]!='\0';i++)
        {
            if(str[i]==str[i+1])
                cont++;
            else
            {
                printf("%d%c",cont,str[i]);
                cont=1;
                continue;
            }
        }
        printf("\n");
    }
    return 0;
}

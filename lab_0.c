#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a;
    float b;

    scanf ("%d %f",&a,&b);
    switch(a)
    {
        case 0:
             printf("The Centigrade is %.2f",(b-32)*5/9);
             break;
        case 1:
             printf("The Fahrenheit is %.2f",b*1.8+32);
             break;
    }
    return 0;
}




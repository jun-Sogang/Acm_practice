#include <stdio.h>

int d[32];

int main()
{
    int i,j;
    int input;

    scanf("%d",&input);
    d[0]=1;
    d[1]=0;
    d[2]=3;
    d[3]=0;

    for(i=4; i<=input; i++)
    {
        d[i]=3*d[i-2];
        for(j=2; j*2<=i; j++)
            d[i]+=2*d[i-2*j];
    }
    printf("%d\n",d[input]);
    return 0;
}

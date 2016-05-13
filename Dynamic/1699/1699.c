#include <stdio.h>
#define MIN(a,b) a>b ? b : a
int d[100001];
int main()
{
    int i,j,input;
    scanf("%d",&input);

    d[0]=0;
    d[1]=1;
    for(i=1; i<=input; i++)
    {
        d[i]=d[i-1]+1;
        for(j=1; i-j*j>=0; j++)
        {
            d[i]=MIN(d[i-j*j]+1,d[i]);
        }
    }
    printf("%d\n",d[input]);
    return 0;
}

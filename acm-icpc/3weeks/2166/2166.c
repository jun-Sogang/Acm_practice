#include<stdio.h>

int main()
{
    long long x[10001],y[10001];
    int count;
    int i,j;
    long double sum=0;

    scanf("%d",&count);

    for(i=0; i<count; i++)
    {
        scanf("%lld %lld",&x[i],&y[i]);
    }
    for(i=0; i<count-1; i++)
    {
        sum+=x[i]*y[i+1];
    }
    sum+=x[count-1]*y[0];
    for(i=0; i<count-1; i++)
    {
        sum-=x[i+1]*y[i];
    }
    sum-=x[0]*y[count-1];
    sum/=2;
    if(sum<0)
        sum*=-1;
    printf("%0.1Lf\n",sum);


    return 0;
}

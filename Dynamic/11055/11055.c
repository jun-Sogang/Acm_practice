#include<stdio.h>

int a[1001];
int d[1001];

int main()
{
    int n,i,j;
    long long ans=0;
    scanf("%d",&n);
    
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    d[0]=a[0];
    for(i=1; i<n; i++)
    {
        d[i]=a[i];
        for(j=0; j<i; j++)
        {
            if(a[i]>a[j] && d[i] < d[j]+a[i])
            {
                d[i]=d[j]+a[i];
            }
        }
    }
    for(i=0; i<n; i++)
    {
        if(ans<d[i])
            ans=d[i];
    }
    printf("%lld\n",ans);
    
    return 0;
}

#include <stdio.h>

int a[1001];
int d[1001];

int main()
{
    int n,i,j;
    int ans=0;
    scanf("%d",&n);

    for(i=0; i<n; i++)
        scanf("%d",&a[i]);

    d[0]=1;
    for(i=1; i<n; i++)
    {
        d[i]=1;
        for(j=0; j<i; j++)
        {
            if(a[i]>a[j] && d[i]<=d[j])
                d[i]=d[j]+1;
        }

    }
    for(i=0; i<n; i++)
    {
        if(ans<=d[i])
                ans=d[i];
    }    
        
    printf("%d\n",ans);
    return 0;
}

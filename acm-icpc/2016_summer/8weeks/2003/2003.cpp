#include <cstdio>
#include <algorithm>
#include <vector>
 
int main()
{
    int a[10001];
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    int ans=0;
    int start=0,end=0,sum=0;
    while(start != n)
    {
        while(sum < m && end != n)
            sum+=a[end++];
        if(sum==m)
            ans++;
        sum-=a[start++];
    }
    printf("%d\n",ans);
    return 0;
}
#include <cstdio>
#include <algorithm>
using namespace std;
int a[10002];
int main()
{
    int n,temp,Max=0;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&temp);
        a[temp]++;
        Max=max(Max,temp);
    }
    for(int i=1; i<=Max; )
    {
        if(a[i]>0)
        {
            printf("%d\n",i);
            a[i]--;
        }
        else
            i++;
    }
}

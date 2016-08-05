#include <cstdio>
#include <algorithm>
using namespace std;
int a[1000002];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    printf("%d %d",a[0],a[n-1]);
}

#include <cstdio>
int main()
{
    int n,a,sum=0;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%1d",&a);
        sum+=a;
    }
    printf("%d",sum);
}

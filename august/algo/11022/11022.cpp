#include <cstdio>
int main()
{
    int n;
    scanf("%d",&n);
    int a,b;
    int i=1;
    while(scanf("%d %d",&a,&b)==2)
    {
        printf("Case #%d: %d + %d = %d\n",i++,a,b,a+b);
        if(i>n)
            break;
    }
}

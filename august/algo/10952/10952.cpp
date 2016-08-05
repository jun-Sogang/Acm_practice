#include <cstdio>
int main()
{
    int a,b;
    while(1)
    {
        scanf("%d %d",&a,&b);
        if(a==b && a==0)
            break;
        printf("%d\n",a+b);
    }
}

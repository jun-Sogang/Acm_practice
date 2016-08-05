#include <cstdio>
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        if(i==n-1)
        {
            for(int j=0; j<=i*2; j++)
                printf("*");
            continue;
        }
        for(int j=i; j<n-1; j++)
            printf(" ");
        printf("*");
        for(int j=0; j<2*i-1; j++)
            printf(" ");
        if(i!=0)
            printf("*");
        puts("");
    }
}

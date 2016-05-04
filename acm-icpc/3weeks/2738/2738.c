#include<stdio.h>
#define MAX_SIZE 101

int main()
{
    int n,m;
    int i,j;
    int a[MAX_SIZE][MAX_SIZE];
    int b[MAX_SIZE][MAX_SIZE];
    scanf("%d %d",&n,&m);
    
    for(i=0;i<n;i++)
    {
        for(j=0; j<m;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0; j<m;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            if(j)
                printf(" ");
            printf("%d",a[i][j]+b[i][j]); 
        }
        printf("\n");
    }
    
    return 0;
}

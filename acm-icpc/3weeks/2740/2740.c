#include<stdio.h>
#define MAX_SIZE 101
int main()
{
    int a[MAX_SIZE][MAX_SIZE];
    int b[MAX_SIZE][MAX_SIZE];
    int i,j,l;
    int n,m,k;
    int sum=0;
    scanf("%d %d",&n, &m);

    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            scanf("%d",&a[i][j]);
    scanf("%d %d",&m, &k);
    for(i=0; i<m; i++)
        for(j=0; j<k; j++)
            scanf("%d",&b[i][j]);
    for(i=0; i<n; i++)
    {
        for(j=0; j<k; j++)
        {
            if(j)
                printf(" ");
            sum=0;
            for(l=0; l<m; l++)
                {
                    sum+=a[i][l]*b[l][j];
                }
            printf("%d",sum);
            
        }
        printf("\n");
    }
    return 0;
}

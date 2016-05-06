#include<stdio.h>
char table[11][11];
int main()
{
    int n,m;
    int i,j;
    scanf("%d %d",&n, &m);
    char temp;
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            temp=getchar();
            if(temp != '\n')
                table[i][j]=temp;
            else
                j--;
        }
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            printf("%c",table[i][m-j-1]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}

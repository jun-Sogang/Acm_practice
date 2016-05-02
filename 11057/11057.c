#include <stdio.h>

int N[1001][11]={0};

int main()
{
    int n=0;
    int i=0,j=0,k=0;
    int tempSum=0;
    int answer=0;

    scanf("%d",&n);

    for(i=0; i<n; i++)
    {
        if(i==0)
        {
            for(j=0; j<10; j++)
                N[i][j]=1;
        }
        else
            {
                for(j=0; j<10; j++)
                {
                    for(k=0; k<=j; k++)
                        tempSum+=N[i-1][k];
                    N[i][j]=tempSum%10007;
                    tempSum=0;
                }
            }
    }
    for(i=0; i<10; i++)
        answer+= N[n-1][i]%10007;
    answer%= 10007;

    printf("%d\n",answer);
}


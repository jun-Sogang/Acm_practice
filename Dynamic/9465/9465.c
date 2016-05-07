#include <stdio.h>
#define MAX(a, b) ( (a) > (b) ? (a) : (b) )

long long score[100001][2];
long long D[100001][3];

int main()
{
    int count;
    int i,j;
    int n;
    long long answer=0;

    scanf("%d",&count);

    while(count--)
    {
        scanf("%d",&n);

        for(i=0; i<n; i++)
            scanf("%lld",&score[i][0]);
        for(i=0; i<n; i++)
            scanf("%lld",&score[i][1]);
        
        for(i=0; i<n; i++)
        {
            if(i==0)
            {
                D[i][0]=0;
                D[i][1]=score[i][0];
                D[i][2]=score[i][1];
            }
            else
            {
                D[i][0]=MAX(D[i-1][1],D[i-1][2]);
                D[i][1]=MAX(D[i-1][0],D[i-1][2]) + score[i][0];
                D[i][2]=MAX(D[i-1][0],D[i-1][1]) + score[i][1];
            }
        }
        for(i=0; i<n; i++)
            answer=MAX(MAX(D[i][0],D[i][1]),MAX(answer,D[i][2]));
        printf("%lld\n",answer);
        answer=0;
    }
    return 0;
}

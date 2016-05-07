#include <stdio.h>

long long D[100][2];
int main()
{
    int input;
    int i;
    long long answer;

    scanf("%d",&input);

    for(i=0; i<input; i++)
    {
        if(i==0)
        {
            D[i][0]=0;
            D[i][1]=1;
        }
        else
        {
            D[i][1]=D[i-1][0];
            D[i][0]=D[i-1][0]+D[i-1][1];
        }
    }
    answer = D[input-1][0]+D[input-1][1];

    printf("%lld\n",answer);

    return 0;
}

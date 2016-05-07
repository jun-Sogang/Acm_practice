#include <stdio.h>
long long  mod = 1000000000LL;
int main()
{
    long long  memo[10][101];
    long long  rmemo[101];
    int input;
    
    scanf("%d",&input);
    
    for(int i=1; i<=input; i++)
    {
       
        if(i == 1)
        {
            for(int j=0; j<=9; j++)
            {
                memo[j][i]=1LL;
            }
        }
        else
            for(int j=0; j<=9; j++)
            {
                if(j==0)
                    memo[j][i]=memo[j+1][i-1];
                else if(j==9)
                    memo[j][i]=memo[j-1][i-1];
                else
                    memo[j][i]=memo[j-1][i-1]+memo[j+1][i-1];
                memo[j][i] = memo[j][i]%mod;
            }
        
    }
    for(int i=1; i<=9; i++)
    {
        rmemo[input]+=memo[i][input];
        rmemo[input]%=mod;
    }
    printf("%lld\n",rmemo[input]);

    return 0;
}

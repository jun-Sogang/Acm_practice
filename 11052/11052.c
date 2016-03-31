#include <stdio.h>

int memo[10002];
int cost[10002];

int dynamic(int input);

int main()
{
    int input;
    scanf("%d",&input);
    for(int i=1; i<=input; i++)
        scanf("%d",&cost[i]);
    printf("%d\n",dynamic(input));

    return 0;
}
int dynamic(int input)
{
    if(input==0)
        return memo[input];
    if(memo[input]>0)
        return memo[input];
    for(int i=1; i<=input; i++)
        if(memo[input] < cost[i]+dynamic(input-i))
            memo[input] = cost[i]+dynamic(input-i);
    return memo[input];
}

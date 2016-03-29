#include<stdio.h>

int dynamic(int input);
int memo[1001];
int main()
{
    int input;
    scanf("%d",&input);

    printf("%d\n",dynamic(input));
    return 0;
}
int dynamic(int input)
{
    if(input == 1)
    {
        memo[input] = 1;
        return memo[input];
    }
    if(input == 2)
    {
        memo[input] =2;
        return memo[input];
    }

    if(memo[input] > 0)
        return memo[input]%10007;
    memo[input] = dynamic(input-1) + dynamic(input-2);
    
    return memo[input]%10007;;
}

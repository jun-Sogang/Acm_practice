#include<stdio.h>

int memo[1001]={0, 1, 3};
int dynamic(int input);

int main()
{
    int input;
    scanf("%d",&input);
    printf("%d\n",dynamic(input)); 
    return 0;
}
int dynamic(int input)
{
    if( memo[input] > 0)
        return memo[input]%10007;
    memo[input] = dynamic(input-1) + 2*dynamic(input-2);
    return memo[input]%10007;
}

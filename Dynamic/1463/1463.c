#include<stdio.h>

int memo[1000001];

int count(int input);

int main()
{
    int input;
    scanf("%d",&input);
    printf("%d\n",count(input));

    return 0;
}

int count(int input)
{
    if(input == 1)
        return 0;
    if(memo[input]>0)
        return memo[input];
    memo[input] = count(input-1)+1;
   

    if(input%2 == 0 && memo[input] > count(input/2)+1)
        memo[input] = count(input/2)+1;
    if(input%3 == 0 && memo[input] > count(input/3)+1)
        memo[input] = count(input/3)+1;
    return memo[input];
}

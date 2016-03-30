#include<stdio.h>

int memo[12]={0,1,2,4};;
int dynamic(int input);
int main()
{
    int loop;
    int input;
    scanf("%d",&loop);
    while(loop--){
        scanf("%d",&input);
        printf("%d\n",dynamic(input));
    }
    return 0;
}
int dynamic(int input)
{
    if(memo[input] > 0)
        return memo[input];
    memo[input]= dynamic(input-1)+dynamic(input-2)+dynamic(input-3);
    return memo[input];
}

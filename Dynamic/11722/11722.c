#include<stdio.h>

int a[1001];
int d[1001];

int main()
{
    int input;
    int i,j;
    int answer=0;
    scanf("%d",&input);
    for(i=0; i<input; i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0; i<input; i++)
    {
        d[i]=1;
        for(j=i-1; j>=0; j--)
        {
            if(a[i]<a[j] && d[i]<=d[j])
            {
                d[i]=d[j]+1;
            }
        }
    }
    for(i=0; i<input;i++)
    {
        if(answer<d[i])
            answer=d[i];
    }
    printf("%d\n",answer);
    return 0;
}
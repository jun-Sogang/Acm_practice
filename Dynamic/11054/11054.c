#include<stdio.h>

int a[1001];
int a_swap[1001];
int d_dec[1001];
int d_inc[1001];

int main()
{
    int input;
    int i,j;
    int answer=0;
    int temp;
    scanf("%d",&input);
    for(i=0; i<input; i++)
    {
        scanf("%d",&a[i]);
    }

    for(i=0; i<input; i++)
    {
        a_swap[i]=a[input-i-1];
    }
    d_inc[0]=1;
    for(i=1; i<input; i++)
    {
        d_inc[i]=1;
        for(j=0; j<i; j++)
        {
            if(a[i]>a[j] && d_inc[i]<=d_inc[j])
                d_inc[i]=d_inc[j]+1;
        }

        
    }
    d_dec[0]=1;
    for(i=1; i<input; i++)
    {
        d_dec[i]=1;
        for(j=0; j<i; j++)
        {
            if(a_swap[i]>a_swap[j] && d_dec[i]<=d_dec[j])
                d_dec[i]=d_dec[j]+1;
        }
    }
    
    
    answer=d_inc[0]+d_dec[input-1]-1;
    
    for(i=0; i<input;i++)
    {
        answer=(d_inc[i]+d_dec[input-i-1]-1)>answer ? (d_inc[i]+d_dec[input-i-1]-1):answer;
    }
    printf("%d\n",answer);
    return 0;
}

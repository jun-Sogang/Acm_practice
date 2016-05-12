#include <stdio.h>
#define MAX(a,b) (a) > (b) ? (a) : (b)
long long d[100001];
long long a[100001];
int main()
{
    int i,j;
    int input;
    long long answer;

    scanf("%d",&input);

    for(i=0; i<input; i++)
    {
        scanf("%lld",&a[i]);
    }
    d[0]=a[0];

    for(i=1; i<input; i++)
    {
        d[i]=a[i];
        d[i]=MAX(d[i-1]+a[i],d[i]);
    }
    answer=d[0]; 
    for(i=0; i<input ;i++)
    {
        answer=MAX(answer,d[i]);
    }
    printf("%lld\n",answer);
    return 0;
}

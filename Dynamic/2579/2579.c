#include<stdio.h>
#define MAX(a,b) a>b ? a:b
int a[301];
int d[301][3];

int main()
{
    int input;
    int i;
    int answer=0;

    scanf("%d",&input);
    for(i=0;i<input; i++)
        scanf("%d",&a[i]);
    d[0][0]=a[0];
    d[0][1]=a[0];
    d[0][2]=0;
    for(i=1; i<input; i++){
            d[i][0]=d[i-1][1]+a[i];
            d[i][1]=d[i-1][2]+a[i];
            d[i][2]=MAX(d[i-1][1],d[i-1][0]);
    }
   // for(i=0; i<input; i++)
     //   answer=MAX(MAX(d[i][0],d[i][1]),answer);//마지막이 포함 안됐을때의 MAX값도 구함
    answer=MAX(d[input-1][0],d[input-1][1]);
    printf("%d\n",answer);
    return 0;
}

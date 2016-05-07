#include <stdio.h>
#define MAX(a,b) ((a)>(b)) ? (a):(b)
int D[10001][3];
int score[10001];

int main()
{
    int glass;
    int ans=0;

    scanf("%d",&glass);

    for(int i=0; i<glass; i++)
        scanf("%d",&score[i]);
    for(int i=0; i<glass; i++)
    {
        if(i==0)
        {
            D[i][0] = 0;
            D[i][1] = score[i];
            D[i][2] = 0;
        }
        else 
        {
            D[i][0] = MAX(D[i-1][0],MAX(D[i-1][1],D[i-1][2]));
            D[i][1] = D[i-1][0] + score[i];
            D[i][2] = D[i-1][1] + score[i];
        }
    }
   
    for(int i=0; i<glass; i++)
    {
        ans=MAX(MAX(ans,D[i][0]),MAX(D[i][1],D[i][2]));
    }
    printf("%d\n",ans);
    return 0;
}

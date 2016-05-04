#include<stdio.h>
#define MAX_SIZE 101
int main()
{
    int field[MAX_SIZE][MAX_SIZE];
    int n;
    int x,y;
    int i,j;
    int score=0;
    for(i=0; i<MAX_SIZE;i++)
        for(j=0; j<MAX_SIZE;j++)
            field[i][j]=0;

    scanf("%d",&n);
    while(n--)
    {
        scanf("%d %d",&x,&y);
        for(i=0; i<10; i++)
            for(j=0; j<10; j++)
            {
                field[x+i][y+j]=1;
            }
    }
    for(i=0; i<MAX_SIZE;i++)
        for(j=0; j<MAX_SIZE;j++)
            score+=field[i][j];
    printf("%d\n",score);
}

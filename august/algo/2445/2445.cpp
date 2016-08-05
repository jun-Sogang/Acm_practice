#include <cstdio>
int main(){
    int i,j,k;
    int size;
    scanf("%d",&size);
    for(i=0;i<size;i++)
    {
        for(j=0;j<i+1;j++)
            printf("*");
        for(k=0;k<(size-1-i)*2;k++)
            printf(" ");
        for(j=0;j<i+1;j++)
            printf("*");
        puts("");
    }
    size-=1;
    for(i=0;i<size;i++)
    {
        for(j=0;j<size-i;j++)
            printf("*");
        for(k=0;k<(i+1)*2;k++)
            printf(" ");
        for(j=0;j<size-i;j++)
            printf("*");
            puts("");
    }
}

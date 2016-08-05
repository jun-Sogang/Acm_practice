#include <cstdio>
int main(){
    int i,j,k;
    int size;
    scanf("%d",&size);
    for(i=0;i<size;i++)
    {
        for(k=0;k<size-1-i;k++)
            printf(" ");
        for(j=0;j<(i+1)*2-1;j++)
            printf("*");
        printf("\n");
    }
}

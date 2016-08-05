#include <cstdio>
int main(){
    int i,j,k;
    int size;
    
    scanf("%d",&size);
    for(i=0;i<size;i++)
    {
        for(k=0;k<i;k++)
            printf(" ");
        for(j=0;j<size-i;j++)
            printf("*");
        puts("");
    }
}

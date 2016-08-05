#include <cstdio>
int main(){
    int i,j,k;
    int size;
    
    scanf("%d",&size);
    for(i=0;i<size;i++)
    {
        for(k=0;k<size-i-1;k++)
            printf(" ");
        for(j=0;j<i+1;j++)
        {
            printf("*");
        }
        puts("");
    }
}

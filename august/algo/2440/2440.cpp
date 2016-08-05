#include <cstdio>
int main(){
    int i,j;
    int size;
    
    scanf("%d",&size);
    for(i=0;i<size;i++)
    {
        for(j=0;j<size-i;j++)
            printf("*");
        puts("");
    }
}

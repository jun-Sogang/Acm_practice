#include <cstdio>
int main(){
    int l,n,m,ans=0;
    int a=0,b=0,c=0;
    scanf("%d %d %d",&l,&m,&n);
 
    for(int i=0; i<15*28*19; i++){
        a++;
        b++;
        c++;
        ans++;
        if(a>15)
            a=1;
        if(b>28)
            b=1;
        if(c>19)
            c=1;
        if(a==l && b==m && c==n){
            printf("%d\n",ans);
            return 0;
        }
    }
}
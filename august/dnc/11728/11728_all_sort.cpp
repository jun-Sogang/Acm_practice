#include <cstdio>
#include <algorithm>
using namespace std;
int a[1000001];
int b[1000001];
int c[2000001];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0; i<n; i++)
        scanf("%d",a+i);
    for(int i=0; i<m; i++)
        scanf("%d",b+i);
    int i=0;
    for(;i<n;i++)
        c[i]=a[i];
    for(int j=0; j<m; j++)
        c[i++]=b[j];
    sort(c,c+n+m);
    for(i=0; i<n+m; i++)
        printf("%d ",c[i]);
    puts("");
}
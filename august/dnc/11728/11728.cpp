#include <cstdio>
#include <algorithm>
using namespace std;
int a[1000001];
int b[1000001];
int c[2000001];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0; i<n; i++){
        scanf("%d",a+i);
    }
    sort(a,a+n);
    for(int i=0; i<m; i++){
        scanf("%d",b+i);
    }
    sort(b,b+m);
    int i=0,j=0,k=0;
    while(i<n && j<m){
        if(a[i]<=b[j])
            c[k++]=a[i++];
        else
            c[k++]=b[j++];
    }
    while(i<n)
        c[k++]=a[i++];
    while(j<m)
        c[k++]=b[j++];
    for(int i=0; i<n+m; i++)
        printf("%d ",c[i]);
    puts("");
}

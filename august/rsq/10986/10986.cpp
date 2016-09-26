#include <cstdio>
typedef long long ll;
ll a[1000001];
ll tree[3000003];
int n,m;
ll ans=0;
ll init(int node, int start, int end){
    if(start == end)
        return eree[node] = a[start];
    else{
        return tree[node] = init(node*2,start,(start+end)/2) + init(node*2+1,(start+end)/2+1,end);
    }
}
ll query(int node, int start, int end, int i, int j){
    if(
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0; i<n; i++)
        scanf("%lld",&a[i]);
    init(1,0,n-1);
    for(int j=0; j<n; j++)
        for(int i=0; i<j; i++)
            query(1,0,n-1,i,j);
    printf("%lld\n",ans);
}

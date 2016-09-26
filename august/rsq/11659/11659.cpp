#include <cstdio>
typedef long long ll;
ll a[100001];
ll tree[300003];
ll init(int node, int start, int end){
    if(start == end)
        return tree[node]=a[start];
    else
        return tree[node]=init(node*2,start,(start+end)/2) + init(node*2+1,(start+end)/2+1,end);
}
ll sum(int node,int start, int end, int i,int j){
    if(i>end || j<start)
        return 0;
    if(i<=start && end<=j)
        return tree[node];
    return sum(node*2,start,(start+end)/2,i,j)+sum(node*2+1,(start+end)/2+1,end,i,j);
}
int main(){
    int N,M;
    scanf("%d %d",&N,&M);
    for(int i=0; i<N; i++)
        scanf("%lld",&a[i]);
    init(1,0,N-1);
    for(int i=0; i<M; i++){
        int a,b;
        scanf("%d %d",&a,&b);
        printf("%lld\n",sum(1,0,N-1,a-1,b-1));
    }
}

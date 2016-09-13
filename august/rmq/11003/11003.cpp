#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll; 
ll a[5000003];
ll tree[15000003];
void init(int node, int start, int end){
    if(start==end)
        tree[node] = a[start];
    else{
        init(node*2,start,(start+end)/2);
        init(node*2+1,(start+end)/2+1,end);
        tree[node]=min(tree[node*2],tree[node*2+1]);
    }
}
ll query(int node, int start, int end, int i, int j){
    if(i<0)
        i=0;
    if(i>end || j<start)
        return -1;
    if(start>= i && j>=end)
        return tree[node];
    ll m1=query(node*2,start, (start+end)/2,i,j);
    ll m2=query(node*2+1,(start+end)/2+1, end, i,j);
    if(m1==-1)
        return m2;
    else if(m2==-1)
        return m1;
    else
        return min(m1,m2);
}
int main(){
    int n,l;
    scanf("%d %d",&n,&l);
    for(int i=0; i<n; i++)
        scanf("%lld",&a[i]);
    init(1,0,n-1);
    for(int i=0; i<n; i++)
        printf("%lld ",query(1,0,n-1,i-l+1,i));
    puts("");
}

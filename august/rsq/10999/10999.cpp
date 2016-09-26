#include <cstdio>
typedef long long ll;
ll a[1000003];
ll tree[3000009];
ll init(int node, int start, int end){
	if(start == end)
		return tree[node] = a[start];
	else
		return tree[node] = init(2*node,start,(start+end)/2) + init(2*node+1,(start+end)/2+1,end);
}

ll sum(int node, int start, int end, int i, int j){
	if(i > end || j < start)
		return 0;
	if(i<=start && end <= j)
		return tree[node];
	return sum(node*2,start,(start+end)/2,i,j)+sum(node*2+1,(start+end)/2+1,end,i,j);
}
void update(int node, int start, int end, int i, int diff){
	if(i>end || i < start)
		return ;
	tree[node]+=diff;
	if(start != end){
		update(node*2, start, (start+end)/2,i,diff);
		update(node*2+1,(start+end)/2+1, end, i, diff);
	}
}

int main(){
	int N,M,K;
	scanf("%d %d %d",&N,&M,&K);
	for(int i=0; i<N; i++){
		int temp;
		scanf("%dd",&temp);
		a[i]=temp;
	}
	init(1,0,N-1);
	ll A,b,c;
	for(int i=0; i<M+K; i++){
		scanf("%lld %lld %lld",&A,&b,&c);
		if(A==1){
			ll d;
            scanf("%lld",&d);
			update(1,0,N-1,b-1,diff);
		}
		else{
			printf("%lld\n",sum(1,0,N-1,b-1,c-1));
		}
	}
}

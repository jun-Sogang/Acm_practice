#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int array_n[100003];
vector < pair < int , int > > array_m;
int tree[300009];
void init(int node, int start, int end){
	if(start==end)
		tree[node] = array_n[start];
	else{
		init(node*2,start,(start+end)/2);
		init(node*2+1,(start+end)/2+1,end);
		tree[node]=min(tree[node*2],tree[node*2+1]);
	}
	
}
int query(int node, int start, int end, int i, int j){
	if(i> end || j<start){
		return -1;
	}
	if(i<=start && end <=j)
		return tree[node];
	int m1=query(2*node,start,(start+end)/2,i,j);
	int m2=query(2*node+1,(start+end)/2+1,end,i,j);
	if(m1==-1)
		return m2;
	else if(m2==-1)
		return m1;
	else
		return min(m1,m2);
}
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	array_m.resize(m+1);
	for(int i=0; i<n; i++){
		scanf("%d",array_n+i);
	}	
	init(1,0,n-1);
	for(int i=0; i<m; i++){
		int a,b;
		scanf("%d %d",&a,&b);
		printf("%d\n",query(1,0,n-1,a-1,b-1));
	}

	
}
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int array_n[100003];
int min_tree[300009];
int max_tree[300009];
void min_init(int node, int start, int end){
	if(start==end)
		min_tree[node] = array_n[start];
	else{
		min_init(node*2,start,(start+end)/2);
		min_init(node*2+1,(start+end)/2+1,end);
		min_tree[node]=min(min_tree[node*2],min_tree[node*2+1]);
	}
	
}
void max_init(int node, int start, int end){
	if(start==end)
		max_tree[node] = array_n[start];
	else{
		max_init(node*2,start,(start+end)/2);
		max_init(node*2+1,(start+end)/2+1,end);
		max_tree[node]=max(max_tree[node*2],max_tree[node*2+1]);
	}
	
}
int min_query(int node, int start, int end, int i, int j){
	if(i> end || j<start){
		return -1;
	}
	if(i<=start && end <=j)
		return min_tree[node];
	int m1=min_query(2*node,start,(start+end)/2,i,j);
	int m2=min_query(2*node+1,(start+end)/2+1,end,i,j);
	if(m1==-1)
		return m2;
	else if(m2==-1)
		return m1;
	else
		return min(m1,m2);
}
int max_query(int node, int start, int end, int i, int j){
	if(i> end || j<start){
		return -1;
	}
	if(i<=start && end <=j)
		return max_tree[node];
	int m1=max_query(2*node,start,(start+end)/2,i,j);
	int m2=max_query(2*node+1,(start+end)/2+1,end,i,j);
	if(m1==-1)
		return m2;
	else if(m2==-1)
		return m1;
	else
		return max(m1,m2);
}
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0; i<n; i++){
		scanf("%d",array_n+i);
	}	
	min_init(1,0,n-1);
	max_init(1,0,n-1);
	for(int i=0; i<m; i++){
		int a,b;
		scanf("%d %d",&a,&b);
		printf("%d %d\n",min_query(1,0,n-1,a-1,b-1),max_query(1,0,n-1,a-1,b-1));
	}

	
}
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 18; // log(2,100000)
const int Input = 100003;
int N,M;
int parent[Input][MAX];
int depth[Input];
vector < int > adj[Input];
void makeTreeByDFS(int cur){
	for(int next: adj[cur]){
		if(depth[next] == -1){
			parent[next][0]=cur;
			depth[next] = depth[cur]+1;
			makeTreeByDFS(next);
		}
	}
}
int main(){
	scanf("%d", &N);
	for(int i=0; i<N-1; ++i){
		int u,v;
		scanf("%d %d",&u,&v);
		u--;
		v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	memset(parent,-1,sizeof(parent));
	fill(depth,depth+N,-1);
	depth[0] = 0;
	makeTreeByDFS(0);

	//parent 배열 채움
	for(int j=0; j<MAX-1; ++j){
		for(int i=1; i<N; ++i){
			if(parent[i][j] != -1)
				parent[i][j+1] = parent[parent[i][j]][j];
		}
	}
	
	//쿼리 입력받기
	scanf("%d", &M);
	for(int i=0; i<M; i++){
		int u,v;
		scanf("%d %d",&u,&v);
		u--;
		v--;
		if(depth[u] < depth[v])
			swap(u,v);
		int diff = depth[u]-depth[v];
		for(int j=0; diff; j++){
			if(diff % 2)
				u = parent[u][j];
			diff/=2;
		}
		if(u != v){
			for(int j=MAX-1; j>=0; --j){
				if(parent[u][j] != -1 && parent[u][j] != parent[v][j]){
					u=parent[u][j];
					v=parent[v][j];
				}
			}
			u = parent[u][0];
		}
		
		printf("%d\n",u+1);
	}

}


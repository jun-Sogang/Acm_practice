#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector < vector < int > > v;
bool visited[1004];
int cycle = 0;
void dfs(int V) {
	visited[V] = true;
	for (int i = 0; i < (int)v[V].size(); i++) {
		if (visited[v[V][i]] != true)
			dfs(v[V][i]);
		else
		{
			cycle++;
			break;
		}
	}
}
int main()
{
	int k,t,a;
	scanf("%d%*c", &k);
	while(k--){
		scanf("%d", &t);
		v.resize(t + 1);
		cycle = 0;
		
		for (int i = 1; i <= t; i++){
			scanf("%d", &a);
			v[i].push_back(a);
	//		v[a].push_back(i);
		}
		for (int i = 1; i <= t; i++) {
			if (visited[i] != true)
				dfs(i);
		}
		printf("%d\n", cycle);
		for (int i = 1; i <= t; i++) {
			v[i].clear();
			visited[i] = false;
		}
	}
	
}
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector < vector < int > > v;
bool visited[20001];
int color[20004];
bool ok = true;
void dfs(int V,int t) {
	color[V] = t;
	visited[V] = true;
	for (int i = 0; i < (int)v[V].size(); i++) {
		if (color[v[V][i]] == 0)
			dfs(v[V][i], 3 - t);
		else if (color[v[V][i]] == t) {
			ok = false;
			break;
		}
	}
}
int main()
{
	int k;
	int V, E;

	scanf("%d%*c", &k);
	while (k--)
	{
		scanf("%d %d", &V, &E);
		v.resize(V + 1);
		ok = true;
		for (int i = 1; i <= V; i++){
			color[i] = 0;
			v[i].clear();
			visited[i] = false;
		}

		for (int i = 0; i < E; i++){
			int a, b;
			scanf("%d %d", &a, &b);
			v[a].push_back(b);
			v[b].push_back(a);
		}
		for (int i = 1; i <= V; i++)
			if(visited[i]==false)
				dfs(i,1);
		if (ok)
			printf("YES\n");
		else
			printf("NO\n");
	}
}
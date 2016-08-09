#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector < vector < int > > v;
bool visit[1001];

void dfs(int V) {
	printf("%d ", V);
	visit[V] = true;
	for (int i = 0; i < (int)v[V].size(); i++) {
		if (visit[v[V][i]] != true) {
			dfs(v[V][i]);
		}
	}
}
void bfs(int V) {
	queue < int > que;
	que.push(V);
	visit[V] = true;
	while (!que.empty()) {
		int x = que.front();
		que.pop();
		printf("%d ", x);
		for (int i = 0; i < (int)v[x].size(); i++) {
			if (visit[v[x][i]] != true) {
				que.push(v[x][i]);
				visit[v[x][i]] = true;
			}
		}
	}

}
int main()
{
	int n, m, V;
	scanf("%d %d %d", &n, &m, &V);
	v.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	//for (int i = 0; i < (int)v.size(); i++)
		//sort(v[i].begin(), v[i].end());
	dfs(V);
	puts("");
	for (int i = 0; i < n + 1; i++)
		visit[i] = false;
	bfs(V);
}
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
vector < vector < int > > v;
bool visit[1001];
int connected = 0;
void bfs(int V) {
	queue < int > que;
	que.push(V);
	visit[V] = true;
	while (!que.empty()) {
		int x = que.front();
		que.pop();
		for (int i = 0; i < (int)v[x].size(); i++) {
			if (visit[v[x][i]] != true) {
				que.push(v[x][i]);
				visit[v[x][i]] = true;
			}
		}
	}
	connected++;
}
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	v.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 0; i < (int)v.size(); i++)
		sort(v[i].begin(), v[i].end());
	for (int i = 1; i <= n; i++)
		if(visit[i] == false)
			bfs(i);
	printf("%d\n", connected);
}
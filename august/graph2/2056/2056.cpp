#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
vector < int > v[10001];
int indegree[10001];
int t[10001];
int ans[10001];
int answer = 0;
queue < int > q;
void bfs(int V) {
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < v[x].size(); i++) {
			indegree[v[x][i]]--;
			ans[v[x][i]] = max(t[v[x][i]] + ans[x], ans[v[x][i]]);
			if (indegree[v[x][i]] == 0) {
				q.push(v[x][i]);
			}
		}
	}
}
int main() {
	int n, time, precedence;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &time, &precedence);
		t[i] = time;
		for (int j = 0; j < precedence; j++){
			int pre;
			scanf("%d", &pre);
			indegree[i]++;
			v[pre].push_back(i);
		}
	}
	for (int i = 1; i <= n; i++)
		if (indegree[i] == 0)
		{
			q.push(i);
			ans[i] = t[i];
		}
	bfs(1);
	for (int i = 1; i <= n; i++)
		answer = max(answer, ans[i]);
	printf("%d\n", answer);
}
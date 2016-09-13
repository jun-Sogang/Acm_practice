#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
vector < int > v[32001];
int indegree[32001];
bool visit[32001];
int n, m;
priority_queue < int , vector < int >, greater < int > > q;
void bfs() {
	while (!q.empty()) {
		int x = q.top();
		if (visit[x] != true) {
			printf("%d ", x);
			visit[x] = true;
		}
		q.pop();
		for (int i = 0; i < v[x].size(); i++) {
			indegree[v[x][i]]--;
			if (indegree[v[x][i]] == 0 && visit[v[x][i]] != true) {
				q.push(v[x][i]);
			}
		}

	}
}
int main() {
	int temp1, temp2;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &temp1, &temp2);
		v[temp1].push_back(temp2);
		v[temp2].push_back(temp1);
		indegree[temp2]++;
	}
	for (int i = 0; i < n; i++)
		if (visit[i + 1] != true && indegree[i + 1] == 0){
			q.push(i + 1);
		}
	bfs();
	puts("");
}

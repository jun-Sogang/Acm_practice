#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
vector < int > v[501];
int complete_time[501];
int cumulate_time[501];
int indegree[501];
queue < int > q;
void bfs() {
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < v[x].size(); i++) {
			indegree[v[x][i]]--;
			cumulate_time[v[x][i]] = max(complete_time[v[x][i]] + cumulate_time[x], cumulate_time[v[x][i]]);
			if (indegree[v[x][i]] == 0)
				q.push(v[x][i]);
		}
	}
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int tmp;
		scanf("%d", &tmp);
		complete_time[i] = tmp;
		while (1) {
			scanf("%d", &tmp);
			if (tmp == -1)
				break;
			indegree[i]++;
			v[tmp].push_back(i);
		}
	}
	for (int i = 1; i <= n; i++)
		if (indegree[i] == 0){
			q.push(i);
			cumulate_time[i] = complete_time[i];
		}
	bfs();
	for (int i = 1; i <= n; i++)
		printf("%d\n", cumulate_time[i]);
}
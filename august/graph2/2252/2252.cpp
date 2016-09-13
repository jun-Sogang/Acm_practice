#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
vector < int > v[32001];
int indegree[32001];
bool visit[32001];
int n, m;
void bfs(int V) {
	queue < int > q;
	q.push(V);
	visit[V] == true;
	printf("%d ", V);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < v[x].size(); i++) {
			indegree[v[x][i]]--;
			if (indegree[v[x][i]] == 0 && visit[v[x][i]]!=true) {
				q.push(v[x][i]);
				printf("%d ", v[x][i]);
				visit[v[x][i]] = true;
			}
		}

	}
}
int main() {
	int temp1, temp2;
	int first;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &temp1, &temp2);
		v[temp1].push_back(temp2);
		v[temp2].push_back(temp1);
		indegree[temp2]++;
		if (i == 0)
			first = temp1;
	}
	for(int i=0; i<n; i++)
		if(visit[i+1]!=true && indegree[i+1]==0)
			bfs(i+1);
	puts("");
}

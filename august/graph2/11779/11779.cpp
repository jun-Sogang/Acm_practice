#include <cstdio>
#include <queue>
#include <vector>
#include <stack>
using namespace std;
vector < pair < int , int > > v[1001];
int dist[1001];
int visited[1001];
int inf = 1000000000;
priority_queue< pair < int, int > > pq;
int walk[1001];
int dijkstra(int start,int end) {
	dist[start] = 0;
	walk[start] = -1;
	pq.push(make_pair(0, start));
	while (!pq.empty()) {
		int c = pq.top().second;
		pq.pop();
		if (visited[c] == 1)
			continue;
		visited[c] = 1;
		for (int j = 0; j < v[c].size(); j++) {
			int n = v[c][j].first;
			if (dist[n] > dist[c] + v[c][j].second) {
				dist[n] = dist[c] + v[c][j].second;
				pq.push(make_pair(-dist[n], n));
				walk[n] = c;
			}
		}
	}
	return dist[end];
}

int main(){
	int n, m;
	int U, V, cost;
	int start, end;
	vector < int > ans;
	scanf("%d %d", &n, &m);
	fill(dist, dist + n + 1, inf);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &U, &V, &cost);
		v[U].push_back(make_pair(V, cost));
	}
	scanf("%d %d", &start, &end);
	printf("%d\n",dijkstra(start, end));
	stack < int > st;
	int x = end;
	while (x != -1) {
		st.push(x);
		x = walk[x];
	}
	printf("%d\n", st.size());
	while (!st.empty()) {
		printf("%d ", st.top());
		st.pop();
	}
	puts("");
}

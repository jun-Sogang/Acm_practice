#include <cstdio>
#include <algorithm>
#include <vector>
#define MAX 100000000
using namespace std;

vector < pair < pair < int, int >, int > > g;
int dist[601], n,m,w;
bool bellman_ford(int start) {
	dist[start] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < g.size(); j++) {
			if (dist[g[j].first.second] > dist[g[j].first.first] + g[j].second) {
				dist[g[j].first.second] = dist[g[j].first.first] + g[j].second;
				if (i == n - 1)
					return false;
			}
		}
	}
	return true;
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d", &n, &m,&w);
		fill(dist, dist + n + 1, MAX);
		g.clear();
		for (int i = 0; i < m; i++) {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			g.push_back(make_pair(make_pair(a, b), c));
			g.push_back(make_pair(make_pair(b, a), c));
		}
		for (int i = 0; i < w; i++) {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			g.push_back(make_pair(make_pair(a, b), -c));
		}
		dist[1] = 0;
		if (!bellman_ford(1)) {
			printf("YES\n");
		}
		else
			printf("NO\n");
	}
}
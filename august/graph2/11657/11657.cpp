#include <cstdio>
#include <algorithm>
#include <vector>
#define MAX 100000000
using namespace std;

vector < pair < pair < int, int >, int > > g;
int dist[501], n,m;
bool bellman_ford(int start) {
	dist[start] = 0;
	for(int i=0; i<n; i++)
		for(int j=0; j<g.size(); j++)
			if (dist[g[j].first.second] > dist[g[j].first.first] + g[j].second) {
				dist[g[j].first.second] = dist[g[j].first.first] + g[j].second;
					if (i == n-1) {
						printf("-1\n");
						return false;
					}
			}
	return true;
}
int main() {
	scanf("%d %d", &n, &m);
	fill(dist, dist + n + 1, MAX);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		g.push_back(make_pair(make_pair(a, b), c));
	}
	if (!bellman_ford(1)) {
		return 0;
	}
	for (int i = 2; i <= n; i++)
	{
		if (dist[i] != MAX)
			printf("%d\n", dist[i]);
		else
			printf("%d\n", -1);
	}
}
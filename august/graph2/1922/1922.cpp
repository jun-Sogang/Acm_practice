#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector < pair < int , pair < int, int > > >v; // °¡ÁßÄ¡ a->b
int parent[1001];
int Find(int x) {
	return x == parent[x] ? x : parent[x] = Find(parent[x]);
}
void Union(int x, int y) {
	parent[parent[x]] = parent[y];
}
int main() {
	int n, m;
	long long ans = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		parent[i] = i;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		v.push_back(make_pair(c, make_pair(a, b)));
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < m; i++) {
		int U = v[i].second.first;
		int V = v[i].second.second;
		if (Find(U) == Find(V))
			continue;
		Union(U, V);
		ans += v[i].first;
	}
	printf("%lld\n", ans);
}
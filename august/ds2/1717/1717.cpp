#include <cstdio>
#include <algorithm>
using namespace std;
int parent[1000102];
int Find(int x) {
	return x == parent[x] ? x : parent[x] = Find(parent[x]);
}
void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	if (x != y)
		parent[y] = x;
}
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i <= n; i++)
		parent[i] = i;
	for (int i = 0; i < m; i++) {
		int zero_check, a, b;
		scanf("%d %d %d", &zero_check, &a, &b);
		if (zero_check == 0)
			Union(a, b);
		else {
			int A = Find(a);
			int B = Find(b);
			if (A==B)
				printf("YES\n");
			else
				printf("NO\n");
		}

	}
}
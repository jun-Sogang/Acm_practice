#include <cstdio>
#include <vector>
using namespace std;
vector < int > tree[100001];
int parent[100001];

void find_parent(int root)
{
	for (int i = 0; i < tree[root].size(); i++)
	{
		int next = tree[root][i];
		if (parent[root] == next)
			continue;
		parent[next] = root;
		find_parent(next);
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n-1; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	find_parent(1);
	for (int i = 2; i <= n; i++)
		printf("%d\n", parent[i]);
	return 0;
}
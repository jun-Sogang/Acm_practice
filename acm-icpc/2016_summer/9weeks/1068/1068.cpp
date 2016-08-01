#include <cstdio>
#include <vector>
using namespace std;

vector < int > tree[51];
int cnt = 0;
void preorder(int start)
{
	if (tree[start].size() == 0)
	{
		cnt++;
		return;
	}
	preorder(tree[start][0]);
	preorder(tree[start][1]);
}
int main()
{
	int n;
	int root;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);
		if (a == -1)
		{
			root = i;
			continue;
		}
		tree[a].push_back(i);
	}
	int del;
	scanf("%d", &del);
	tree[del].clear();
	preorder(root);
	printf("%d\n", (cnt - 1));
	return 0;
}
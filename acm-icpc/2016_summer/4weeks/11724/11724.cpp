#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;	

int connected = 0;
vector < vector < int > >v;
bool check[1005] = { false, };
void bfs(int start)
{
	queue < int > q;
	int cnt = 0;

	q.push(start);
	check[start] = true;
	while (!q.empty())
	{
		int now = q.front();
		for (int i = 0; i < v[now].size(); i++)
		{
			if (check[v[now][i]] == false)
			{
				q.push(v[now][i]);
				check[v[now][i]] = true;
				cnt++;
			}
		}
		q.pop();
	}
	if (cnt)
		connected++;

}
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	v.resize(n + 1);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i < n + 1; i++)
		bfs(i);
	for (int i = 1; i < n + 1; i++)
		if (v[i].size() == 0)
			connected++;
	printf("%d\n", connected);
	return 0;
}
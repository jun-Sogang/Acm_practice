#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int n, m;
vector < vector < int > > v;
int cnt=0;
void bfs(int start)
{
	queue < int > q;
	bool check[101] = { false, };
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
}
int main()
{
	
	scanf("%d %d", &n, &m);
	v.resize(n + 1);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	bfs(1);
	printf("%d\n", cnt);
	return 0;
}
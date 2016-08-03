#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

vector<vector<pair<int, int > > > g;

bool visited[100002];
int n, m;
typedef struct planet {
	int a, b, c;
};
planet info[100001];
long long prim(int s)
{
	int i = 0, j, cost, u, cnt = 0;
	long long ans = 0;
	priority_queue<pair <int, int> >pq;
	for (; i < g[s].size(); i++)
		pq.push(make_pair(g[s][i].first, g[s][i].second));
	visited[s] = true;
	cnt++;
	while (cnt != n-1)
	{
		u = pq.top().second;
		cost = pq.top().first;
		pq.pop();
		if (!visited[u]) {
			visited[u] = true;
			ans += cost;
			for (j = 0; j < g[i].size(); j++)
				pq.push(make_pair(g[u][j].first, g[u][j].second));
			cnt++;
		}
	}
	return ans;
}
int main()
{
	int i = 0, u, v, cost, U, V;
	long long ans = 0;
	scanf("%d", &n);
	g.resize(n + 1);
	for (i = 0; i < n; i++)
	{
		scanf("%d %d %d", &info[i].a, &info[i].b, &info[i].c);
	}
	long long Min = -1, temp;
	int ai, aj;
	for (i=0; i < n; i++)
	{
		Min = -1;
		for (int j = i+1; j < n; j++)
		{
			if (i != j)
			{
				temp = min(abs(info[i].a - info[j].a), min(abs(info[i].b - info[j].b),abs( info[i].c - info[j].c)));
				if (Min == -1 || temp<Min)
				{
					Min = temp;
					ai = i;
					aj = j;
					if (temp == 0)
						j = n;
				}
			}
			
		}
		if (i != n) {
			g[ai].push_back(make_pair(-Min, aj));
			g[aj].push_back(make_pair(-Min, ai));
		}
	}
	printf("%lld", -prim(1));
	return 0;
}
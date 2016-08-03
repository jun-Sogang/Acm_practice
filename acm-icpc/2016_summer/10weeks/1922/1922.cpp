#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

vector < pair<int, pair < int , int > > > g;
int parent[10002];
int Find(int x)
{
	return x==parent[x]?x:parent[x]=Find(parent[x]);
}
void Union(int x, int y)
{
	parent[parent[x]]=parent[y];
}

int main()
{
	int n,m,i=0,u,v,cost,U,V;
	long long ans=0;
	scanf("%d %d",&n,&m);
	for(; i<n; i++)
		parent[i]=i;
	for(i=0; i<m; i++)
	{
		scanf("%d %d %d",&u, &v, &cost);
		g.push_back(make_pair(cost,make_pair(u,v)));
	}
	sort(g.begin(),g.end());
	for(i=0; i<m; i++)
	{
		U=g[i].second.first,V=g[i].second.second;
		if(Find(U)==Find(V))
			continue;
		Union(U,V);
		ans+=g[i].first;
	}
	printf("%lld\n",ans);
	return 0;
}
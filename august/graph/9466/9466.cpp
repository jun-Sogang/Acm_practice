#include <cstdio>
#include <vector>
using namespace std;
vector < vector < int > > v;
long long visited[1000001];
long long cn = 1;
int first;
int cycle_vertex = 0;
void dfs(int V)
{
	visited[V] = cn++;
	for (int i = 0; i < (int)v[V].size(); i++) {
		if (visited[v[V][i]] == -1) {
			visited[first] - 1;
			cycle_vertex++;
			break;
		}
		if (visited[v[V][i] ] ==0 || visited[v[V][i]] <first)
			dfs(v[V][i]);
		else if(visited[v[V][i]]!=first){
			visited[first] = -1;
			cycle_vertex++;
			break;
		}

		
	}
}
int main()
{
	int t,n,input;
	scanf("%d%*c", &t);
	while (t--) {
		scanf("%d", &n);
		v.resize(n + 1);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &input);
			v[i].push_back(input);
		}
		for (int i = 1; i <= n; i++) {
			first = cn;
			dfs(i);
		}
		printf("%d\n", cycle_vertex);
		cycle_vertex = 0;
		for (int i = 0; i <= n; i++)
			v[i].clear();
	}
}
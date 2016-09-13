#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;
vector < int > v[100005];
bool visited[100005];
int d[100005];
int s[100005];
int ans = 0;
int cnt = 1;
int set=0;
void dfs(int V)
{
	d[V] = cnt++;
	s[V] = set; // 한 dfs당 순회한 정점을 묶어놓기 위함. 한 dfs당 최초로 하나의 사이클을 찾으면 된다.
	visited[V] = true;
	if (visited[v[V][0]] == false)
		dfs(v[V][0]);
	else {
		if(s[V]==s[v[V][0]])	
			ans+=cnt - d[v[V][0]];
	}

}
int main()
{
	int t, n, input;
	scanf("%d%*c", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &input);
			v[i].push_back(input);
		}
		for (int i = 1; i <= n; i++) {
			if (visited[i] == false) {
				set++;
				dfs(i);
			}
		}
		printf("%d\n", n - ans);

		for (int i = 1; i <= n; i++)
			v[i].clear();
		memset(visited, false, sizeof(visited));
		ans = 0;

	}
}

#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

int tomato[1001][1001];
int cnt = 0;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int ans[1001][1001];
int m, n;

void bfs(int i, int j) {
	queue < pair < int, int > > que;
	que.push(make_pair(i, j));
	ans[i][j] = 1;
	while (!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;
		que.pop();
		for (int l = 0; l < 4; l++) {
			int nx = x + dx[l];
			int ny = y + dy[l];
			if (nx>=0 && nx<n && ny>=0 && ny<m && tomato[nx][ny] == 0 && (ans[nx][ny] > ans[x][y]+1||ans[nx][ny]==0)) {
				que.push(make_pair(nx, ny));
				ans[nx][ny] = ans[x][y]+1;
			}
		}
	}
}
int main() {
	int Max = 0;
	int total = 0;
	scanf("%d %d",&m, &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			scanf("%d", &tomato[i][j]);
			total += tomato[i][j];
			ans[i][j] = tomato[i][j];
		}
	if (total == m*n) {
		return printf("%d\n", 0);
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if(tomato[i][j]==1)
				bfs(i, j);
		}
			
	for(int i=0; i<n; i++)
		for (int j = 0; j < m; j++) {
			if (ans[i][j] == 0 )
				return printf("%d\n", -1);
		}
	for(int i=0; i<n; i++)
		for (int j = 0; j < m; j++) {
			Max = max(Max, ans[i][j]);
		}
	return printf("%d\n", Max-1);

}

#include <cstdio>
int dp[505][505];
int a[505][505];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int n, m;
int go(int x, int y) {
	int next_x, next_y;
	if (x == n - 1 && y == m - 1)
		return 1;
	if (dp[x][y] > 0)
		return dp[x][y];
	for (int i = 0; i < 4; i++) {
		next_x = dx[i] + x;
		next_y= dy[i] + y;
		if (next_x < n && next_x >= 0 && next_y < m &&next_y >= 0 && a[next_x][next_y] < a[x][y])
			dp[next_x][next_y] += go(next_x, next_y);
	}
	return dp[next_x][next_y];
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &a[i][j]);
	printf("%d\n", go(0,0));
}
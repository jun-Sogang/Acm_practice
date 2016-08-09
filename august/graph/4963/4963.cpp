#include <cstdio>
#include <queue>
using namespace std;

int map[51][51];
int land[51][51];
int dx[8] = { 0, 0, 1, -1,-1,-1,1,1 };
int dy[8] = { 1, -1, 0, 0 ,-1,1,-1,1};
int cnt = 0;
void bfs(int i, int j,int cnt) {
	queue < pair < int , int > > que;
	que.push(make_pair(i, j));
	land[i][j] = cnt;
	while (!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;
		que.pop();
		for (int l = 0; l < 8; l++) {
			int nx = x + dx[l];
			int ny = y + dy[l];
			if (land[nx][ny] ==0 && map[nx][ny]==1) {
				que.push(make_pair(nx, ny));
				land[nx][ny] = cnt;
			}
		}
	}
}
int main() {
	int a, b;
	while (scanf("%d %d", &a, &b)) {
		if (a == 0 && b == 0)
			break;
		for (int i = 0; i < b; i++)
			for (int j = 0; j < a; j++)
				scanf("%1d", &map[i][j]);
		for(int i=0; i<b; i++)
			for (int j = 0; j < a; j++) {
				if(land[i][j]==0 && map[i][j]==1)
					bfs(i, j, ++cnt);
			}
		printf("%d\n", cnt);
		cnt = 0;
		for(int i=0; i<b; i++)
			for (int j = 0; j < a; j++) {
				map[i][j] = 0;
				land[i][j] = 0;
			}
	}
}
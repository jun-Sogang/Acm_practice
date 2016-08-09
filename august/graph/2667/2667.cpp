#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

map  < int, int > m;
int group[27][27];
int input[27][27]; 
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int n;
vector <  int > v;
void bfs(int i, int j, int cnt){
	queue< pair < int, int > > que;
	que.push(make_pair(i, j));
	group[i][j] = cnt;
	while (!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;
		que.pop();
		for (int l = 0; l < 4; l++) {
			int nx = x + dx[l];
			int ny = y + dy[l];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n && input[nx][ny]==1 && group[nx][ny]==0) {
				que.push(make_pair(nx,ny));
				group[nx][ny] = cnt;
			}
		}
	}
}
int main(){
	int cnt=1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%1d", &input[i][j]);
	for(int i=0; i<n; i++)
		for (int j = 0; j < n; j++) {
			if (input[i][j] == 1 && group[i][j] == 0)
				bfs(i, j, cnt++);
		}
	printf("%d\n", cnt-1);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (group[i][j] != 0)
				m[group[i][j]]++;
	for (int i = 1; i <= cnt - 1; i++)
		v.push_back(m[i]);
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
		printf("%d\n", v[i]);
}
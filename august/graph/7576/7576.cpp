#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
int tomato[1001][1001] = {0, };
int visited[1001][1001];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int ans = 0;
queue <pair <int, int> > que;



void bfs() {
	while (!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;
		
		que.pop();

		for (int k = 0; k < 4; ++k) {
			int next_x = x + dx[k];
			int next_y = y + dy[k];

			if (tomato[next_x][next_y] != -1 && visited[next_x][next_y] == -1 && next_x >= 0 && next_x < N && next_y >= 0 && next_y < M) {
				que.push(make_pair(next_x, next_y));
				visited[next_x][next_y] = visited[x][y] + 1;
				if(ans < visited[next_x][next_y]) ans = visited[next_x][next_y]; 
			}
		} 
	}

}

int main() {
	cin >> M >> N;
	int count = 0;


	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < M; ++j) {
			int input;

			scanf("%d", &input);
			tomato[i][j] = input;
			visited[i][j] = -1;

			if(input == 1) {
				visited[i][j] = 0;
				count += 1;
				que.push(make_pair(i, j));
			}
		}
	}

	if(count == N * M) {
		printf("0\n");
		return 0;
	}

	bfs();

	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < M; ++j) {
			if (visited[i][j] == -1 && tomato[i][j] != -1) {
				printf("-1\n");
				return 0;
			}
		}
	}

	printf("%d\n", ans);
	return 0;
}
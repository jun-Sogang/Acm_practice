#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
using namespace std;

int n;
int map[21][21];
pair <int, int> shark;
int shark_size = 2;
int fish_size = 0;
int devour = 0;

int dx[4] = {0, -1, 1, 0};
int dy[4] = {-1, 0, 0, 1};

void p() {
    
}


int bfs() {
    int move[21][21] = {0, };
    queue <pair <int, int> > q;
    pair <int, int> min_loc;
    int min_move = 99999999;

    q.push(shark);

    while (!q.empty()) {
        pair <int, int> now_shark = q.front();

        q.pop();
        
        for (int i = 0; i < 4; ++i) {
            int next_x = dx[i] + now_shark.first;
            int next_y = dy[i] + now_shark.second;
            
            
            if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < n && move[next_x][next_y] == 0 && shark_size >= map[next_x][next_y]) {
                move[next_x][next_y] = move[now_shark.first][now_shark.second] + 1;
                q.push(make_pair(next_x, next_y));       

                if (map[next_x][next_y] != 0 && map[next_x][next_y] < shark_size && min_move >= move[next_x][next_y]) {
                    
                    if (min_move == move[next_x][next_y]) {
                        // 누가 더 위에 있는지
                        if (min_loc.first == next_x) {
                            if (min_loc.second > next_y) {
                                min_loc = make_pair(next_x, next_y);
                            }
                        }
                        else if (min_loc.first > next_x) {
                            min_loc = make_pair(next_x, next_y);
                        }
                    }
                    else {
                        min_move = move[next_x][next_y];
                        min_loc = make_pair(next_x, next_y);
                    }
                }
            }
        }
    }

    if (min_move != 99999999) {
        devour += 1;
        shark = min_loc;
        map[shark.first][shark.second] = 0;
    } 
    else {
        min_move = 0;
    }
    return min_move;
}

int go() {
    int result = 0;

    if (fish_size == 0) return result;


    while (fish_size--) {
        result += bfs();
        if (shark_size == devour) {
            devour = 0;
            shark_size += 1;
        }
    }

    return result;
}

int main() {

    cin >> n;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &map[i][j]);

            if (map[i][j] == 9) {
                shark = make_pair(i, j);
                map[i][j] = 0;
            }
            else if (map[i][j] != 0) {
                fish_size += 1;
            }
        }
    }

    cout << go() << endl;
    return 0;
}
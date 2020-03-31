#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int r, c;
char map[251][251];
bool flag[251][251] = {false, };
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void go() {
    int sheep = 0;
    int wolf = 0;

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (map[i][j] != '#' && flag[i][j] == false) {
                queue <pair <int, int> > q;
                int now_sheep = 0;
                int now_wolf = 0;
                
                if (map[i][j] == 'v') {
                    now_wolf += 1;
                }
                else if (map[i][j] == 'o') {
                    now_sheep += 1;
                }
                q.push(make_pair(i, j));
                flag[i][j] = true;
                while (!q.empty()) {
                    for (int k = 0; k < 4; ++k) {
                        int next_x = q.front().first + dx[k];
                        int next_y = q.front().second + dy[k];

                        if (next_x >= 0 && next_x < r && next_y >= 0 && next_y < c && flag[next_x][next_y] != true) {
                            if (map[next_x][next_y] == 'v') {
                                now_wolf += 1;
                            }
                            else if (map[next_x][next_y] == 'o') {
                                now_sheep += 1;
                            }
                            flag[next_x][next_y] = true;
                            
                            q.push(make_pair(next_x, next_y));
                        }
                    }
                    q.pop();
                }
                if (now_sheep > now_wolf) {
                    sheep += now_sheep;
                }
                else if (now_sheep <= now_wolf) {
                    wolf += now_wolf;
                }
            }
        }
    }
    printf("%d %d\n", sheep, wolf);
}

int main() {

    cin >> r >> c;

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            char input;

            cin >> input;

            map[i][j] = input;
            
            if (map[i][j] == '#') {
                flag[i][j] = true;
            }
        }
    }
    go();

    return 0;
}
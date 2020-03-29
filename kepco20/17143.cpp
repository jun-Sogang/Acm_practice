#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int map[101][101] = {0, };
int r, c, m;

// r, c, s, d, z
queue <pair <pair <int, int>, pair<int, pair <int, int> > > > v;

void shark_moving() {
    queue <pair <pair <int, int>, pair<int, pair <int, int> > > > v_temp;
    int map_temp[101][101] = {0, };

    while (!v.empty()) {
        
        int now_r = v.front().first.first;
        int now_c = v.front().first.second;
        int now_s = v.front().second.first;
        int now_d = v.front().second.second.first;

        for (int i = 0; i < now_s; ++i) {
            if (now_d == 1) {
                if (now_r == 0) {
                    now_d = 2;
                    now_r += 1;
                }
                else now_r -= 1;
            }
            else if (now_d == 2) {
                if (now_r == r - 1) {
                    now_d = 1;
                    now_r -= 1;
                }
                else now_r += 1;
            }
            else if (now_d == 3) {
                if (now_c == c - 1) {
                    now_d = 4;
                    now_c -= 1;
                }
                else now_c += 1;
            }
            else if (now_d == 4) {
                if (now_c == 0) {
                    now_d = 3;
                    now_c += 1;
                }
                else now_c -= 1;
            }
        }
        
        v.front().first.first = now_r;
        v.front().first.second = now_c;
        v.front().second.first = now_s;
        v.front().second.second.first = now_d;

        if (map_temp[now_r][now_c] == 0) {
            map_temp[now_r][now_c] = v.front().second.second.second;
            v_temp.push(v.front());

        }
        else if (map_temp[now_r][now_c] < v.front().second.second.second) {
            int eat_size = map_temp[now_r][now_c];

            map_temp[now_r][now_c] = v.front().second.second.second;
            
            // 잡아 먹혔을 때
            while (!v_temp.empty()) {
                int now_size = v_temp.front().second.second.second;

                if (now_size == eat_size) {
                    v_temp.pop();
                    break;
                }
                v_temp.push(v_temp.front());
                v_temp.pop();
            }
            
            v_temp.push(v.front());

        } else {

        }

        v.pop();
    }
    v = v_temp;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            map[i][j] = map_temp[i][j];
        }
    }
}

int capture(int c) {
    int captured_shark_size = 0;
    for (int i = 0; i < r; ++i) {
        if (map[i][c] != 0) {
            captured_shark_size = map[i][c];
            map[i][c] = 0;
            break;
        }
    }
    if (captured_shark_size != 0) {
        while (!v.empty()) {
            int now_size = v.front().second.second.second;

            if (now_size == captured_shark_size) {
                v.pop();
                break;
            }
            v.push(v.front());
            v.pop();
        }
    }
    
    return captured_shark_size;
}


int result() {
    int ans = 0;

    for (int i = 0; i < c; ++i) {
        ans += capture(i);
        shark_moving();
    }
    return ans;
}

int main() {

    cin >> r >> c >> m;

    for (int i = 0; i < m; ++i) {
        int x1, x2, x3, x4, x5;

        cin >> x1 >> x2 >> x3 >> x4 >> x5;

        if (x4 == 1) {
            x3 = x3 % (2 * r - 2);
        }
        else if (x4 == 2) {
            x3 = x3 % (2 * r - 2);
        }
        else if (x4 == 3) {
            x3 = x3 % (2 * c - 2);
        }
        else if (x4 == 4) {
            x3 = x3 % (2 * c - 2);
        }

        map[x1 - 1][x2 - 1] = x5;
        v.push(make_pair(make_pair(x1 - 1, x2 - 1), make_pair(x3, make_pair(x4, x5))));
    }

    cout << result() << endl;
}
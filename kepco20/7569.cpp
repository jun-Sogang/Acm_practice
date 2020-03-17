#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int box[101][101][101];
int m, n, h;

int dm[6] = {1, -1, 0, 0, 0, 0};
int dn[6] = {0, 0, 1, -1, 0, 0};
int dh[6] = {0, 0, 0, 0, 1, -1};

// height, n, m
queue <pair <int, pair <int, int> > > flag;
int checked[101][101][101] = {0, };

int bfs() {
    int result = 0;

    while (!flag.empty()) {
        int now_m = flag.front().second.second;
        int now_n = flag.front().second.first;
        int now_h = flag.front().first;

      //  cout << now_m << now_n << now_h << endl;
        flag.pop();

        for (int i = 0; i < 6; ++i) {
            int next_m = now_m + dm[i];
            int next_n = now_n + dn[i];
            int next_h = now_h + dh[i];

            if (next_m >=0 && next_m < m && next_n >= 0 && next_n < n && next_h >= 0 && next_h < h) {
                if (checked[next_h][next_n][next_m] == 0 && box[next_h][next_n][next_m] == 0) {
                    checked[next_h][next_n][next_m] = 1;
                    flag.push(make_pair(next_h, make_pair(next_n, next_m)));

                    box[next_h][next_n][next_m] = box[now_h][now_n][now_m] + 1;

                    result = max(result, box[next_h][next_n][next_m] - 1);
                }
            }
        }
    }
    
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < m; ++k) {
                if (box[i][j][k] == 0) result = -1;
            }
        }
    }

    return result;
}

int main() {

    cin >> m >> n >> h;

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < m; ++k) {
                int input;

                scanf("%d", &input);
                box[i][j][k] = input;

                if (input == 1) {
                    checked[i][j][k] = 1;
                    flag.push(make_pair(i, make_pair(j, k)));
                }
            }
        }
    }

    cout << bfs() << endl;

    return 0;
}
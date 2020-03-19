#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
using namespace std;

int map[103][103] = {0, };


//   right, up, left, down
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int n, x, y, d, g;

void dragon() {
    vector <int> v;
    
    map[y][x] = 1;
    v.push_back(d);
    map[y + dy[d]][x + dx[d]] = 1;

    x = x + dx[d];
    y = y + dy[d];

    while (g--) {
        for (int i = v.size() - 1; i >= 0; --i) {
            int next_x = x + dx[(v[i] + 1) % 4];
            int next_y = y + dy[(v[i] + 1) % 4];

            if (!(next_x >= 0 && next_x <= 100 && next_y >= 0 && next_y <= 100)) return ;
            
            map[next_y][next_x] = 1;
            v.push_back((v[i] + 1) % 4);
            x = next_x;
            y = next_y;
        }
    }
}

int main() {

    cin >> n;

    while (n--) {
        cin >> x >> y >> d >> g;
        dragon();
    }

    int result = 0;

    for (int i = 0; i <= 100; ++i) {
        for (int j = 0; j <= 100; ++j) {
            if (map[i][j] * map[i + 1][j] * map[i][j + 1] * map[i + 1][j + 1] != 0) {
                result += 1;
            }
        }
    }
    cout << result << endl;
    return 0;
}
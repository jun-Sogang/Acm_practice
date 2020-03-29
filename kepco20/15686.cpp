#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int n, m;
vector <pair <int, int> > store;
vector <pair <int, int> > home;
bool flag[100] = {false, };
int ans = 99999999;

int go(int index, int selected_store) {
    int result = 0;

    if (index == store.size() + 1) return 0;
    if (selected_store == m) {
        for (int i = 0; i < home.size(); ++i) {
            int dist = 99999999;

            for (int j = 0; j < store.size(); ++j) {
                if (flag[j] == true) {
                    dist = min(dist, abs(home[i].first - store[j].first) + abs(home[i].second - store[j].second));
                }
            }
            result += dist;
        }
        ans = min(ans, result);
    }
    
    flag[index] = true;
    go(index + 1, selected_store + 1);
    flag[index] = false;
    go(index + 1, selected_store);

    return ans;
}

int main() {

    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int input;

            cin >> input;

            if (input == 1) {
                home.push_back(make_pair(i, j));
            }
            else if (input == 2) {
                store.push_back(make_pair(i, j));
            }
        }
    }

    cout << go(0, 0) << endl;
    return 0;
}
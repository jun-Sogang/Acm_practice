#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
using namespace std;

int d[10001] = {0, };
int coin[101];
int main() {

    int n, k;
    
    cin >> n >> k;

    for (int i = 1; i <= n; ++i) {
        scanf("%d", &coin[i]);
    }
    d[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            if (coin[i] <= j) {
                d[j] += d[j - coin[i]];
            }
        }
    }
    cout << d[k] << endl;
    return 0;
}
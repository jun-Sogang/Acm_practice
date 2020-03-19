#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    long long result = 0;
    cin >> n >> k;

    vector <pair <int, int> > j;

    vector <int> b;

    for (int i = 0; i < n; ++i) {
        int input1, input2;

        cin >> input1 >> input2;
        j.push_back(make_pair(input1, input2));
    }

    for (int i = 0; i < k; ++i) {
        int input1;

        cin >> input1;
        b.push_back(input1);
    }

    sort(j.begin(), j.end());
    sort(b.begin(), b.end());
    
    priority_queue <int> pq;

    for (int i = 0, l = 0; i <= n && l < k;) {
        if (i == n) {
            if (!pq.empty()) {
                result += pq.top();
                pq.pop();
            }
            l += 1;
        }
        else if (b[l] >= j[i].first) {
            pq.push(j[i].second);
            i += 1;
        }
        else {
            if (!pq.empty()) {
                result += pq.top();
                pq.pop();
            }
            l += 1;
        }
    }
    cout << result << endl;
    return 0;
}
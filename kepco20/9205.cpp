#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
using namespace std;

int t, n;

pair <int, int> home;
pair <int, int> park;

int l1(pair <int, int> a, pair <int, int> b) {
    int result = 0;

    result = abs(a.first - b.first) + abs(a.second - b.second);

    return result;
}

string go(vector <pair <int, int > > v) {
    queue <pair <int, int > > q;

    bool visited[101] = {false, };

    if (l1(home, park) <= 1000) {
        return "happy\n";
    }

    for (int i = 0; i < v.size(); ++i) {
        if (l1(v[i], home) <= 1000) {
            q.push(v[i]);
            visited[i] = true;
        }
    }
    
    while (!q.empty()) {

        if (l1(q.front(), park) <= 1000) {
            return "happy\n";
        }

        for (int i = 0; i < n; ++i) {
            if (visited[i] == false && l1(q.front(), v[i]) <= 1000) {
                q.push(v[i]);
                visited[i] = true;
            }
        }
        q.pop();
    }

    return "sad\n";

}


int main() {

    cin >> t;

    while (t--) {
        vector <pair <int, int> > v;

        cin >> n;
        cin >> home.first >> home.second;

        for (int i = 0; i < n; ++i) {
            int x, y;

            cin >> x >> y;
            v.push_back(make_pair(x, y));
        }
        cin >> park.first >> park.second;

        cout << go(v);
    }
     
    return 0;
}
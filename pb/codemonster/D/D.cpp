#include <cstdio>
#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
pair < double, double > d[100020];
vector < pair < int, pair < int, int > > > v;
double dist(int x1, int y1, int x2, int y2) {
	double temp=(x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1);
	return (double)sqrt(temp);
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		scanf("%d", &t);
		for (int i = 0; i < t; i++) {
			int x, y1, y2;
			scanf("%d %d %d", &x, &y1, &y2);
			v.push_back(make_pair(x, make_pair(y1, y2)));
		}
		for (int i = 0; i < t; i++) {
			if (i == 0) {
				d[i + 1] = make_pair(v[i].first, v[i].first);
				continue;
			}
			double d11 = dist(v[i-1].first, v[i-1].second.first, v[i].first, v[i].second.first)+d[i].first;
			double d12 = dist(v[i-1].first, v[i-1].second.first, v[i].first, v[i].second.second)+d[i].second;
			double d21 = dist(v[i-1].first, v[i-1].second.second, v[i].first, v[i].second.first)+d[i].first;
			double d22 = dist(v[i-1].first, v[i-1].second.second, v[i].first, v[i].second.second)+d[i].second;
			if (d11 > d21)
				d[i + 1].first = d21;
			else
				d[i + 1].first = d11;
			if (d12 > d22)
				d[i + 1].second = d22;
			else
				d[i + 1].second = d12;
		
		}
		if (d[t].first > d[t].second)
			printf("%.2llf", d[t].second);
		else
			printf("%.2llf", d[t].first);

	}
}
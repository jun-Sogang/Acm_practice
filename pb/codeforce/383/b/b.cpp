#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int a[100005];

int main() {
	int n, x;
	long long cnt = 0;
	cin >> n >> x;
	memset(a, 0, sizeof(a));

	for (int i = 0; i < n; ++i) {
		int temp;
		scanf("%d", &temp);
		a[temp]++;
	}
	if (x != 0) {
		for (int i = 0; i <= 100000; ++i) {
			if (a[i] != 0 && i^x <=100000 && i^x>=0) {
				if (a[i^x] != 0) {
					cnt += a[i^x] * a[i];
					a[i^x] = 0;
				}
			}
		}
	}
	else {
		for (int i = 0; i <= 100000; ++i) {
			if (a[i] != 0) {
				cnt += a[i]*(a[i]-1) / 2;
			}
		}
	}
	cout << cnt;
}
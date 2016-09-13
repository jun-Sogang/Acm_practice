#include <cstdio>
#include <algorithm>
using namespace std;

//int a[10001];
pair < int, int > a[10001];
bool b[10001];
int n, m;
long long go(int mid) {
	int count = n-m;
	long long num = 0;
	for (int i = 0; i < m; i++) {
		num += mid / a[i].first;
	}
	return num;

}
int main() {
	int tmp;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &tmp);
		a[i].first = tmp;
		a[i].second = i + 1;
	}
	long long ans = 0;

	if (n <= m) {
		printf("%d\n", n);
		return 0;
	}
	else {
		int left = 0;
		long long right = 2000000000LL * 1000000LL;
		while (left <= right) {
			long long mid = left + (right - left) / 2;
			long long time = go(mid);
			if (time<n-m) {
				left = mid + 1;
			}
			else
				right = mid - 1;
			ans = mid;
		}
	}
	
	//printf("%lld\n", ans);
	int temp = 0;
	int count = n - m;
	for (int i = 0; i < m; i++)
		temp += (ans - 1) / a[i].first;
	//printf("%d\n", temp);
	for (int i = 0; i < m; i++) {
		if (ans%a[i].first == 0)
			temp++;
		if (temp == count)
		{
			printf("%d\n", a[i].second);
			return 0;
		}
	}
}

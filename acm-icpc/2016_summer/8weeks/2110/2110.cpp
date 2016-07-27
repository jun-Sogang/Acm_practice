#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

ll a[200001];

int main()
{
	int n, c;
	int input;

	scanf("%d %d", &n, &c);
	for (int i = 0; i<n; ++i)
	{
		scanf("%lld", &a[i]);
	}
	sort(a, a + n);
	ll start = 0, end = a[n - 1] - a[0], mid;
	ll ans = 0;

	while (start < end) {
		mid = (start + end) / 2;
		int g = 0, cnt = 1;
		for (int i = 1; i<n; i++)
		{
			g += a[i] - a[i - 1];
			if (g >= mid) {
				cnt++;
				g = 0;
			}
		}
		if (cnt < c) {
			end = mid;
		}
		else {
			if (ans < mid)
				ans = mid;
			start = mid + 1;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
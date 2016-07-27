#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int k, n;
	long long a[10001];
	scanf("%d %d", &k, &n);
	for (int i = 0; i < k; i++)
	{
		scanf("%lld", &a[i]);
	}
	sort(a, a + k);
	long long start = 1, end = a[k - 1], mid = 0;
	long long ans=0;

	while (start <= end)
	{
		mid = (start + end) / 2;
		if (!mid)
			mid = 1;
		long long cnt=0;
		for (int i = 0; i < k; i++)
		{
			cnt += a[i] / mid;
		}
		if (cnt >= n)
		{
			if (ans < mid)
				ans = mid;
			start = mid + 1;
		}
		else
			end = mid - 1;
	}
	printf("%lld\n", ans);

	return 0;
}
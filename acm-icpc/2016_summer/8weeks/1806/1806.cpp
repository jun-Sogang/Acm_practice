#include <cstdio>
#include <algorithm>
#include <vector>

typedef long long ll;
int main()
{
	int a[100001];
	int n;
	ll s;
	scanf("%d %lld", &n, &s);
	for (int i = 0; i<n; i++)
		scanf("%d", &a[i]);
	ll ans = n;
	int start = 0, end = 0;
	ll sum = 0;
	while (start != n)
	{
		while (sum < s && end != n)
			sum += a[end++];
		if (sum >= s && ans > end - start)
			ans = end - start;
		sum -= a[start++];
	}
	if (ans != n)
		printf("%lld\n", ans);
	else
		printf("%d\n", 0);

	return 0;
}
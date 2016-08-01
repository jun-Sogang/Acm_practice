#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
	int n;
	long long m;
	vector < long long > v;

	scanf("%d %lld", &n, &m);
	for (int i = 0; i < n; i++)
	{
		long long temp;
		scanf("%lld", &temp);
		v.push_back(temp);
	}
	sort(v.begin(), v.end());

	long long start = 0, end = v.back();
	long long mid = 0;
	long long ans = 0;
	while (start <= end)
	{
		long long sum = 0;
		mid = (start + end) / 2;
		for (int i = 0; i < n; i++)
		{
			if (v[i] > mid)
				sum += v[i] - mid;
		}
		if (m <= sum)
		{
			ans = max(ans, mid);
			start = mid + 1;
		}
		else
			end = mid - 1;
	}
	printf("%lld\n", ans);
	return 0;
}
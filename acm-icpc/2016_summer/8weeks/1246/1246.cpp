#include <cstdio>
#include <algorithm>
using namespace std;
#define pi 1000001
#define node 1001
int main()
{
	int n, m;
	int a[node];
	int sum[node];
	int ans = 0;
	int ans_level = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < m; i++)
		sum[i] = 0;
	for (int i = 0; i < m; i++)
	{
		int temp=a[i];
		int cnt = n;
		for (int j = 0; j < m; j++)
		{
			if (a[j] >= temp&&cnt != 0)
			{
				sum[i] += temp;
				cnt--;
			}
		}
		if (ans < sum[i])
		{
			ans = sum[i];
			ans_level = temp;
		}
	}
	printf("%d %d\n", ans_level, ans);
	return 0;
}
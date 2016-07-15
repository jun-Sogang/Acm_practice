#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#include<functional>
using namespace std;

int main()
{
	int n;
	int m;
	int location;
	long long ans = 0;
	int j = 0;
	int temp;
	int maxV;
	priority_queue < int, vector<int>,greater<int> > negative;
	priority_queue <int > positive;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &location);
		if (location > 0)
			positive.push(location);
		else if(location != 0)
			negative.push(location);
	}
	maxV = max(positive.top(), negative.top()*-1);
	while (!positive.empty())
	{
		temp = positive.top();
		for (j = 0; j < m; j++)
		{
			positive.pop();
			if (positive.empty())
				break;
		}
		ans += temp*2;
	}
	while (!negative.empty())
	{
		temp = negative.top()*-1;
		for (j = 0; j < m; j++)
		{
			negative.pop();
			if (negative.empty())
				break;
		}
		ans += temp*2;
	}
	ans -= maxV;
	printf("%lld\n", ans);
	return 0;
}

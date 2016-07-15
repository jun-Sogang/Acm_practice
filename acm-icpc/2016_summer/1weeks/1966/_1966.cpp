#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	priority_queue < pair < int, int > > q;
	int n;
	int testcase, find;
	int priority;
	int count = 0;

	scanf("%d", &n);
	while (n--)
	{
		count = 1;
		scanf("%d %d", &testcase, &find);
		for (int i = 0; i < testcase; i++)
		{
			scanf("%d", &priority);
			q.push(make_pair(priority, i));
		}
		while (q.top().second != find)
		{
			count++;
			q.pop();
		}
		printf("%d\n", count);
	}
	return 0;
}
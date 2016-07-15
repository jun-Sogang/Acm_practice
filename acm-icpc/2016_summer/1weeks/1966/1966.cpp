#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
	queue < pair < int ,int > > q;
	priority_queue < int > flag;
	int n;
	int priority[101];
	int docu;
	int find;
	int count = 0;
	pair < int, int > temp;
	int maxV=0;
	scanf("%d", &n);
	while (n--)
	{
		count = 1;
		while (!flag.empty())
			flag.pop();
		while (!q.empty())
			q.pop();  //초기화
		scanf("%d %d", &docu, &find);
		for (int i = 0; i < docu; i++)
		{
			scanf("%d", priority + i);
			flag.push(priority[i]);
			q.push(make_pair(priority[i],i));
		}
		while (q.front().first != flag.top())
		{
			temp = q.front();
			q.pop();
			q.push(temp);
		}
		while (q.front().second != find)
		{
			while( q.front().first != flag.top())
			{
				temp = q.front();
				q.pop();
				q.push(temp);
			}
			count++;
			q.pop();
			flag.pop();
			while (q.front().first != flag.top())
			{
				temp = q.front();
				q.pop();
				q.push(temp);
			}
		}
		
		printf("%d\n", count);
	}
	return 0;
}

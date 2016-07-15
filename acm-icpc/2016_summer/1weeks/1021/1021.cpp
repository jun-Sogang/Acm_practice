#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	int n, m;
	int temp;
	int full;
	int count = 0;
	int temp_count;
	deque < int > d;
	queue < int > q;
	scanf("%d %d", &n, &m);
	full = n;
	for (int i = 0; i < n; i++)
		d.push_back(i + 1);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &temp);
		q.push(temp);
	}
	while (m--)
	{
		if (d.front() == q.front())
		{
			d.pop_front();
			q.pop();
		}
		else
		{
			deque < int > temp1 = d;
			deque < int > temp2 = d;
			int temp1_count = 0;
			int temp2_count = 0;
			while (temp1.front() != q.front())
			{
				temp1.push_back(temp1.front());
				temp1.pop_front();
				temp1_count++;
			}
			while (temp2.front() != q.front())
			{
				temp2.push_front(temp2.back());
				temp2.pop_back();
				temp2_count++;
			}
			if (temp1_count > temp2_count)
			{
				count += temp2_count;
				d = temp2;
			}
			else
			{
				count += temp1_count;
				d = temp1;
			}
			d.pop_front();
			q.pop();
		}
	}
	printf("%d\n", count);

	return 0;
}
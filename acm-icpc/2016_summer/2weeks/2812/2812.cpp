#include <cstdio>
#include <queue>
using namespace std;

#define length 500001
int main()
{
	int n, k;
	deque < char > q;
	char s[length];
	int max_num=0;
	scanf("%d %d", &n, &k);
	scanf("%s", s);
	for (int i = 0; i < k; i++)
	{
		while (!q.empty() && q.back() < s[i])
			q.pop_back();
		q.push_back(s[i]);
	}
	for (int i = k; i < n; i++)
	{
		while (!q.empty() && q.back() < s[i])
			q.pop_back();
		q.push_back(s[i]);
		printf("%c", q.front());
		q.pop_front();
	}
	puts("");
	return 0;
}
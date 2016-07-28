#include <cstdio>
#include <algorithm>
using namespace std;

int map[1001][1001];
int dynamic[1001][1001];

int main()
{
	int n, m;
	
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++)
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &map[i][j]);
			if (i == 0 && j == 0)
				dynamic[i][j] = map[i][j];
			else if (j == 0)
				dynamic[i][j] = dynamic[i - 1][j] + map[i][j];
			else if (i == 0)
				dynamic[i][j] = dynamic[i][j - 1] + map[i][j];
		}
	for (int i = 0; i<n; i++)
		for (int j = 0; j < m; j++)
		{
			if (i != 0 && j != 0)
			{
				dynamic[i][j] = max(dynamic[i - 1][j], dynamic[i][j - 1]) + map[i][j];
			}
		}
	printf("%d\n", dynamic[n - 1][m - 1]);

	return 0;
}

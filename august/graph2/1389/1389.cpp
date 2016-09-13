#include <cstdio>
#include <algorithm>
using namespace std;
int a[102][102],n,m;
void floyd_warshall() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
				if (a[j][i] == 1 && a[i][k] == 1)
					a[j][k] ++;
}
int main() {
	scanf("%d %d", &n,&m);
	int MIN = 1000000;
	for (int i = 0; i < m; i++) {
		int from, to;
		scanf("%d %d", &from, &to);
		a[from][to]++;
		a[to][from]++;
	}
	floyd_warshall();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			if(a[i][j]!=0)	
				MIN = min(MIN, a[i][j]);
	}
	printf("%d\n", MIN);
}
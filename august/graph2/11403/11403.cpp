#include <cstdio>
#include <algorithm>
using namespace std;
int a[102][102],n;
void floyd_warshall() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
				if (a[j][i] == 1 && a[i][k] == 1)
					a[j][k] = a[j][i]+
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);
	floyd_warshall();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			printf("%d ", a[i][j]);
		puts("");
	}
}

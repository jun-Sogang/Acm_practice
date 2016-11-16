#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MIN = 1000000;
int a[102][102],n,m;
int sum[102];
void floyd_warshall() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
				if (a[j][k] > a[j][i] + a[i][k]){
					a[j][k]=a[j][i]+a[i][k];
				}
}
int main() {
	scanf("%d %d", &n,&m);
	memset(sum,0,sizeof(sum));
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			a[i][j]=n+1;
		}
	}
	for (int i = 0; i < m; i++) {
		int from, to;
		scanf("%d %d", &from, &to);
		a[from][to]=1;
		a[to][from]=1;
	}
	floyd_warshall();
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(i==j)
				continue;
			sum[j]+=a[i][j];
		}
	}
	int ans=MIN;
	int ans_index=-1;
	for(int i=n; i>0; --i){
		if(ans>=sum[i]){
			ans=sum[i];
			ans_index = i;
		}
	}
	printf("%d\n", ans_index);
}

#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int v[1000001];
int remainder[1000001];
int sum[1000001];
int main() {
	int n,m;
	cin >> n >> m;
	memset(v,0,sizeof(v));
	memset(remainder,0,sizeof(remainder));
	memset(sum,0,sizeof(remainder));
	for (int i = 0; i < n; i++) {
		scanf("%d",&v[i]);
	}
	sum[0]=v[0]%m;
	for(int i=1; i<n; i++){
		sum[i] = (sum[i-1]+v[i])%m;
	}
	for (int i = 0; i < n; i++) {
		remainder[sum[i]%m]++;
	}
	remainder[0]++; // S[0,i]%m == 0 인 경우를 찾기위해
	long long ans=0;
	for(int i=0; i<n; i++)
		if (remainder[i]!=0) {
			ans+=((long long)remainder[i]*((long long)remainder[i]-1))/2;
			}
	cout << ans << "\n";
	return 0;
}

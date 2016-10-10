#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
ll count(ll n) {
	ll ans = 0;
	while (n > 0) {
		ans += n;
		n /= 2;
	}
	return ans;
}
int main() {
	FILE *fp = fopen("input.txt", "r");
	FILE *fp1 = fopen("output.txt", "wt+");
	int t;
	fscanf_s(fp, "%d", &t);
	printf("start\n");
	while (t--) {
		ll x, y;
		fscanf_s(fp,"%lld %lld", &x, &y);
		fprintf_s(fp1,"%lld\n", count(y) - count(x));
		printf("%d\n",t);
	}
}

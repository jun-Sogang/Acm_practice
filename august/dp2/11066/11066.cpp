#include <cstdio>

int dp[505];
int a[505];
void dynamic() {

}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int k;
		scanf("%d", &k);
		for (int i = 0; i < k; i++) {
			scanf("%d", &a[k]);
		}
		dynamic();
	}
}
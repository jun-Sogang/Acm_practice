#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <intrin.h>
using namespace std;
typedef long long ll;
map < int, int > m;
map < ll, ll > tree;
ll bitset_OneCounter(ll n) {
	return __popcnt(n);
}
ll count(ll n) {
	ll num = n - 1;
	ll ans = n - 1;
	while (num>0) {
		num /= 2;
		ans += num;
	}
	return ans;
}
void init(int node, int start, int end) {
	if (start == end)
		tree[node] = bitset_OneCounter(start ^ start + 1);
	else {
		init(node * 2, start, (start + end) / 2);
		init(node * 2 + 1, (start + end) / 2 + 1, end);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
}
int query(int node, int start, int end, int i, int j) {
	if (i > end || j < start)
		return -1;
	if (i <= start && end <= j)
		return tree[node];
	ll m1 = query(2 * node, start, (start + end) / 2, i, j);
	ll m2 = query(2 * node + 1, (start + end) / 2 + 1, end, i, j);
	if (m1 == -1)
		return m2;
	else if (m2 == -1)
		return m1;
	else
		return m1 + m2;
}
int main() {
	int t;
	ll c = 1;
	FILE *fp = fopen("input.txt", "r");
	FILE *fp2 = fopen("output.txt", "wt+");
	fscanf_s(fp, "%d", &t);
	init(1, 2, (1 << 30));
	printf("start\n");
	while (t--) {
		ll from, to;
		ll ans = 0;
		fscanf_s(fp, "%lld %lld", &from, &to);
		ans = query(1, 2, 1 << 30, from, to-1);
			fprintf_s(fp2, "%lld\n", ans);
		printf("%lld\n", c++);
	}
	fclose(fp);
	fclose(fp2);
}

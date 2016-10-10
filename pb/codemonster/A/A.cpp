#include <cstdio>
#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
map < int,int > m;
int tree[100000000];
ll bitset_OneCounter(ll n){
    ll count=0;
    while(n){
        count++;
        n&=(n-1);
    }
    return count;
}
ll count(ll n){
    ll num=n-1;
    ll ans=n-1;
    while(num>0){
        num/=2;
        ans+=num;
    }
    return ans;
}
void init(int node, int start, int end) {
	if (start == end)
		tree[node] = m[(1 <<end)];
	else {
		init(node * 2, start, (start + end) / 2);
		init(node * 2+1 , (start + end) / 2+1 , end);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
}
int query(int node, int start, int end, int i, int j) {
	if (i > end || j < start)
		return -1;
	if (i <= start && end <= j)
		return tree[node];
	int m1 = query(2 * node, start, (start + end) / 2, i, j);
	int m2 = query(2 * node + 1, (start + end) / 2 + 1, end, i, j);
	if (m1 == -1)
		return m2;
	else if (m2 == -1)
		return m1;
	else
		return m1 + m2;
}
int main(){
    int t;
	ll c = 1;
	FILE *fp = fopen("input.txt", "r");
	FILE *fp2 = fopen("output.txt", "wt+");
	fscanf_s(fp,"%d",&t);
	int tmp = 2;
	for (int i = 1; i <= 30; i++) {
		m[tmp] = count(tmp);
		tmp *= 2;
	}
	init(1, 0, 30);
    while(t--){
        ll from,to;
        ll ans=0;
		ll left = 1;
		ll right = 1;
		fscanf_s(fp,"%lld %lld",&from,&to);
		while (1) {
			if ((1<<left) >= from)
				break;
			left++;
		}
		right = left;
		while (1) {
			if ((1<<right)-1 > to) {
				right --;
				break;
			}
			right++;
		}
		ans += query(1, 0, 30, left, right-1);
		for (int i = left+1; i <= right - 1; i++) {
			ans += i + 1;
		}+
		/*
		for (ll i = from; i < (1<<left); i++) {
			ll temp;
			temp = i ^ (i + 1);
			ans += bitset_OneCounter(temp);
		}
		for (ll i = (1<<right) - 1; i < to; i++) {
			if (i == (1 << right) - 1) {
				ans += right;
			}
			if (i + i / 2 - 1 <= to) {
				ans+=query(1,0,30,1,right/2)
			}

		}*/

		/*
		{
			for (ll i = from; i < to; i++) {
				ll temp;
				if ((i&(i - 1)) == 0 && i * 2 - 1 <= to) {
					ans += m[i];
					i = i * 2 - 2;
				}
				else {
					temp = i ^ (i + 1);
					ans += bitset_OneCounter(temp);
				}
			}
		}*/
        fprintf_s(fp2,"%lld\n",ans);
		printf("%lld\n", c++);
    }
	fclose(fp);
	fclose(fp2);
}

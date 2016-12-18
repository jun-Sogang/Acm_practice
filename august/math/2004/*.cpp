#include <cstdio>

typedef long long ll;
int main(){
	ll n, m;
	ll two=0;
	ll five=0;
	scanf("%lld %lld",&n, &m);
	for(ll i=5; i<=n; i*=5){
		five+=n/i;
	}
	for(ll i=5; i<=n-m; i*=5){
		five-=(n-m)/i;
	}
	for(ll i=5; i<=m; i*=5){
		five-=m/i;
	}
	for(ll i=2; i<=n; i*=2){
		two+=n/i;
	}
	for(ll i=2; i<=n-m; i*=2){
		two-=(n-m)/i;
	}
	for(ll i=2; i<=m; i*=2){
		two-=m/i;
	}
	printf("%lld\n",five > two ? two : five);
}

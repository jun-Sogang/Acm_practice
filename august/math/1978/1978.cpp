#include <cstdio>

bool prime[1001]= {false, };
void find_prime(){
	prime[0]=true;
	prime[1]=true;
	for(int i=2; i<=1000; ++i){
		for(int j=i*i; j<=1000; j+=i){
			if(!prime[j])
				prime[j]=true;
		}
	}
	for(int i=0; i<=1000;++i){
		prime[i]=!prime[i];
	}
}
int main(){
	find_prime();
	int n,ans=0;
	scanf("%d",&n);
	for(int i=0; i<n; ++i){
		int temp;
		scanf("%d",&temp);
		if(prime[temp])
			ans++;
	}
	printf("%d\n",ans);
}

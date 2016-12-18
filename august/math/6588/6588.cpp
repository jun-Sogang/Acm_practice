#include <cstdio>

bool prime[1000001]= {false, };
void find_prime(){
	prime[0]=true;
	prime[1]=true;
	for(long long i=2; i<=1000000; ++i){
		for(long long j=i*i; j<=1000000; j+=i){
			if(!prime[j])
				prime[j]=true;
		}
	}
	for(int i=0; i<=1000000;++i){
		prime[i]=!prime[i];
	}
}
int main(){
	find_prime();
	int a;
	while(scanf("%d",&a)){
		if(a==0)
			break;
		for(int i=2; i<a; ++i){
			if(prime[i] && prime[a-i]){
					printf("%d = %d + %d\n",a,i,a-i);
				break;
			}
	
		}
	}
}

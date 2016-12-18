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
	int a,b;
	scanf("%d %d",&a,&b);
	for(int i=a; i<=b; ++i){
		if(prime[i])
			printf("%d\n",i);
	}

}

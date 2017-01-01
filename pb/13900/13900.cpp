#include <cstdio>
int main(){
	int n;
	long long sum=0;
	long long ans=0;
	int a[100001];
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%d",&a[i]);
		if(i!=0){
			ans+=sum*a[i];
		}
		sum+=a[i];
	}
	printf("%lld\n",ans);
}

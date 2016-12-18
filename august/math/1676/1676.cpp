#include <cstdio>
int main(){
	int n;
	int ans=0;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i){
		if(i%125==0){
			ans+=3;
		}
		else if(i%25==0){
			ans+=2;
		}
		else if(i%5==0){
			ans+=1;
		}
	}
	printf("%d\n",ans);
}

#include <cstdio>
#include <stack>
using namespace std;

int main(){
	int n;
	stack < int > s;
	scanf("%d",&n);
	if(n==0){
		printf("%d\n",0);
		return 0;
	}
	while(n){
		if(n&1){
			s.push(1);
			n=(n-1)/-2;
		}
		else{
			s.push(0);
			n=n/-2;
		}
	}
	while(!s.empty()){
		printf("%d",s.top());
		s.pop();
	}
}

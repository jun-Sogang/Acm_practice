#include <cstdio>
#include <stack>
using namespace std;
int main(){
	int a,b;
	scanf("%d %d",&a,&b);
	int m;
	scanf("%d",&m);
	int temp=1;
	for(int i=1; i<m; ++i)
		temp*=a;
	int base_ten=0;
	int input;
	for(int i=0; i<m; ++i){
		scanf("%d",&input);
		base_ten+=input*temp;
		temp/=a;
	}
	stack < int > s;
	while(base_ten){
		s.push(base_ten%b);
		base_ten/=b;
	}
	while(!s.empty()){
		printf("%d ",s.top());
		s.pop();
	}
	if(m==1 && input==0)
		printf("%d\n",0);

}

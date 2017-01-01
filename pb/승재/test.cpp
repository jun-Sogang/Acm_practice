#include <stdio.h>

int main(){
	int res1=0;
	int res2=0;
	int temp;
	int digit=1;
	scanf("%d",&temp);
	int tmp=temp;
	int len=0;
	while(tmp>0){
		tmp/=10;
		digit*=10;
	}
	digit/=10;
	while(temp>=1){
		res1+=(temp%10)*digit;
		digit/=10;
		temp/=10;
	}
	scanf("%d",&temp);
	tmp=temp;
	digit=1;
	while(tmp>0){
		tmp/=10;
		digit*=10;
	}
	digit/=10;
	while(temp>=1){
		res2+=(temp%10)*digit;
		digit/=10;
		temp/=10;
	}
	if(res1>res2)
		printf("%d\n",res1);
	else
		printf("%d\n",res2);
}

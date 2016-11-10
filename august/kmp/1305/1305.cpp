#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
vector < int > preprocessing(string a,int l){
	vector < int > pi(l);
	pi[0]=0;
	int j=0;
	for(int i=1; i<l; ++i){
		while(j>0 && a[i] != a[j]){
			j=pi[j-1];
		}
		if (a[i]==a[j]) {
			pi[i]=j+1;
			j++;
		}
		else{
			pi[i]=0;
		}
	}
	return pi;
}
int main(){
	int l;
	string a;
	cin >> l >> a;
	auto matched = preprocessing(a,l);
	cout << l-matched[l-1] << endl;
}

#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
vector < int > preprocessing(string a){
	int m=a.size();
	vector < int > pi(m);
	int j=0;
	for(int i=1; i<m; ++i){
		while (j>0 && a[i] != a[j]) {
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
	string input;
	cin >> input;
	int size = input.size();
	int MAX=0;
	for(int i=0; i<size; ++i){
		auto matched = preprocessing(input.substr(i,size-i));
		for(auto temp : matched){
			MAX=max(temp,MAX);
		}
	}
	cout << MAX << endl;
}

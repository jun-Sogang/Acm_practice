#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

vector < int > preprocessing(string p){
	int string_size = p.size();
	vector < int > pi(string_size);
	pi[0]=0;
	int j=0;
	for(int i=1; i<string_size; i++){
		while (j>0 && p[i] != p[j]) {
			j=pi[j-1];
		}
		if(p[i]==p[j]){
			pi[i] = j+1;
			j++;
		}
		else{
			pi[i]=0;
		}
	}
	return pi;
}
vector < int > kmp(string t, string p){
	auto pi = preprocessing(p);
	vector < int > ans;
	int n=t.size();
	int m=p.size();
	int j=0;
	for(int i=0; i<n; i++){
		while(j>0 && t[i] != p[j]){
			j=pi[j-1];
		}
		if(t[i] == p[j]){
			if(j==m-1){
				ans.push_back(i-m+1);
				j=pi[j];
			}
			else{
				j++;
			}
		}
	}
	return ans;
}
int main(){
	string t,p;
	getline(cin,t);
	getline(cin,p);
	auto matched = kmp(t,p);
	cout << matched.size() << '\n';
	for(auto index : matched){
		cout << index+1 << ' ';
	}
}

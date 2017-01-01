#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int city[10001];
int depth[10001];
vector < int > vector[10001];
int main(){
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		scanf("%d",&city[i]);
	}
	for(int i=0; i<n-1; i++){
		int a,b;
		scanf("%d %d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	queue < int > q;
	q.push(1);
	depth[1]=1;
	while(!q.empty()){
		int now = q.front();
		q.pop();
		for(int i=0; i<v[now].size(); i++){

		}
	}
}

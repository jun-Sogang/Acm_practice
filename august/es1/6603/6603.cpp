#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
	while(1){
		int n;
		scanf("%d",&n);
		if(n==0)
			break;
		vector < int > num(n);
		for(int i=0; i<n; i++)
			cin >> num[i];
		vector < int > combi;
		for(int i=0; i<n-6; i++)
			combi.push_back(0);
		for(int i=0; i<6; i++)
			combi.push_back(1);
		vector < vector < int > > ans;
		do{
			vector < int > cur;
			for(int i=0; i<n; i++){
				if(combi[i] == 1)
					cur.push_back(num[i]);
			}
			ans.push_back(cur);
		}while(next_permutation(combi.begin(),combi.end()));
		sort(ans.begin(),ans.end());		
		for(int i=0; i<ans.size(); i++){
			for(int j=0; j<6; j++)
				printf("%d ",ans[i][j]);
			puts("");
		}
		puts("");
	}
}

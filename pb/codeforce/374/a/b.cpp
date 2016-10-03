#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector < pair < int , string > > v;
int main(){
    int n,k;
	string ans;
	scanf("%d %d",&n,&k);
    for(int i=0; i<n; i++){
        string temp;
        cin >> temp;
        v.push_back(make_pair(temp.size(),temp));    
    }
	cin >> ans;
	sort(v.begin(), v.end());
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (v[i].first != ans.size())
			count++;
		else
			break;
	}
	int t = 0;
	for (int i = 0; i < n; i++) {
		if (v[i].second == ans)
			t++;
	}
	printf("%d ", count + 1+count/k*5);
	printf("%d", n -t+1+ (n -t)/ k * 5);
	puts("");

}

#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <string>
using namespace std;
bool prime[10001];
bool visit[10001];
int cnt[10001];
void prime_setting(){
	memset(prime,true, sizeof(prime));
	for(int i=2; i<=10000; ++i){
		for(int j=i*i; j<=10000; j+=i){
			if(prime[j])
				prime[j]=false;
		}
	}
}
int change(int now, int index, int num){
	int res;
	if(index == 0 && num == 0)
		return -1;
	string s = to_string(now);
	s[index] = num+'0';
	return stoi(s);
}
int main(){
	prime_setting();

	int n;
	cin >>  n;
	while(n--){
		memset(visit,false,sizeof(visit));
		memset(cnt,0,sizeof(cnt));
		int a,b;
		scanf("%d %d",&a,&b);
		visit[a]=true;
		queue < int > q;
		q.push(a);
		while(!q.empty()){
			int now = q.front();
			q.pop();
			for(int i=0; i<4; ++i){
				for(int j=0; j<=9; ++j){
					int next = change(now,i,j);
					if(next!=-1){
						if(prime[next] && !visit[next]){
							q.push(next);
							cnt[next] = cnt[now]+1;
							visit[next]=true;
						}
					}
				}
			}
		}
		printf("%d\n", cnt[b]);
	}
}

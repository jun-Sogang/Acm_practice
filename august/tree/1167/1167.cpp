#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <cstring>
using namespace std;
vector   < pair < int , int > > v[100004];
bool visit[100004];
int cnt[100004];
int Max=0;
int vertex=0;
void bfs(int V){
    memset(cnt,0,sizeof(cnt));
    memset(visit,false,sizeof(visit));
    queue < int > que;
    que.push(V);
    visit[V]=true;
    while(!que.empty()){
        int x=que.front();
        que.pop();
        for(int i=0; i<(int)v[x].size();i++){
            if(visit[v[x][i].first]!=true){
                cnt[v[x][i].first]=(cnt[x]+v[x][i].second);
                que.push(v[x][i].first);
                visit[v[x][i].first]=true;
                if(Max<cnt[v[x][i].first]){
                    vertex=v[x][i].first;
                    Max=cnt[v[x][i].first];
                }
            }
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        int V;
        int a,length;
        scanf("%d",&V);
        while(scanf("%d",&a)){
            if(a==-1){
                break;
            }
            scanf("%d",&length);
            v[V].push_back(make_pair(a,length));
        }
    }
    bfs(1);
    Max=0;
    bfs(vertex);
    printf("%d\n",Max);
}

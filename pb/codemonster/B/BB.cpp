#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
vector < pair < int, int> > v[1001]; // 출발 , 도착 , 비용
bool visited[1001];
int b[1001];
int inf=1000000000;
int bfs(int s,int t){
    priority_queue < pair < int, int>  > q; //  비용, 도착
    fill(b,b+1001,inf);
    fill(visited,visited+1001,false);
    q.push(make_pair(0,t));
    visited[t]=true;
    while(!q.empty()){
        pair < int , int > x=q.top();
        q.pop();
        for(int i=0; i<(int)v[x.second].size(); i++){
            if(visited[v[x.second][i].first]!=true){
                q.push(make_pair(v[x.second][i].second,v[x.second][i].first));
                visited[v[x.second][i].first]=true;
            }
            if(b[v[x.second][i].first] != inf){
                b[v[x.second][i].first]=max(b[v[x.second][i].first],min(b[x.second],v[x.second][i].second));

            }
            else
                b[v[x.second][i].first]=min(b[x.second],v[x.second][i].second);
            
        }
    }
    return b[s];
}
int main(){
    int q,t,n,m;
    int x,y,z;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i=0; i<m; i++){
            scanf("%d %d %d",&x,&y,&z);
            v[x].push_back(make_pair(y, z));
            v[y].push_back(make_pair(x,z));
        }
        cin >> q;
        int ans=0;
        for(int i=0; i<q; i++){
            int s,t;
            
            scanf("%d %d",&s,&t);
            ans+=bfs(s,t);
        }
        cout << ans << endl;
        for(int i=0; i<1001; i++)
            v[i].clear();
    }
}
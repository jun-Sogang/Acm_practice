#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

vector < pair < int , int > > v[801];
int dist[801];
int visited[801];
int inf=100000000;
priority_queue < pair < int , int > > pq;
void New();
int dijkstra(int start,int end){
    New();
    dist[start]=0;
    pq.push(make_pair(0,start));
    while(!pq.empty()){
        pair< int , int> tmp = pq.top();
        pq.pop();
        int c=tmp.second;
        if(visited[c]==1)
            continue;
        for(int j=0; j<v[c].size(); j++){
            int n=v[c][j].first;
            if(dist[n]>dist[c]+v[c][j].second){
                dist[n]=dist[c]+v[c][j].second;
                pq.push(make_pair(-dist[n],n));
            }
        }
    }
    return dist[end];
}
int n,e,ans1=0,ans2=0;
void New(){
    fill(dist,dist+n+1,inf);
    fill(visited,visited+n+1,0);
}
int main(){
    int U,V,cost;
    int f,s;
    scanf("%d %d",&n,&e);
    for(int i=0; i<e; i++){
        scanf("%d %d %d",&U,&V,&cost);
        v[U].push_back(make_pair(V,cost));
        v[V].push_back(make_pair(U,cost));
    }
    scanf("%d %d",&f,&s);

    ans1+=dijkstra(1,f);
    ans1+=dijkstra(f,s);
    ans1+=dijkstra(s,n);
    ans2+=dijkstra(1,s);
    ans2+=dijkstra(s,f);
    ans2+=dijkstra(f,n);
    int ans=min(ans1,ans2);
    if(ans>=inf)
        printf("-1\n");
    else
        printf("%d\n",ans);
}

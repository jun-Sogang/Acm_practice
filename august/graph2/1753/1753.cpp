#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
int dist[20001];
int visited[20001];
int inf=1000000000;
vector < pair < int , int > > v[20001];
priority_queue<pair < int , int > > pq;

void dijkstra(int start){
    dist[start]=0;
    pq.push(make_pair(0,start));
    while(!pq.empty()){
        pair < int , int > tmp = pq.top();
        pq.pop();
        int c= tmp.second;
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
}

int main(){
    int V,E;
    int from,to,cost;
    int start;
    scanf("%d %d %d",&V,&E,&start);
    fill(dist,dist+V+1,inf);
    for(int i=0; i<E; i++){
        scanf("%d %d %d",&from,&to,&cost);
        v[from].push_back(make_pair(to,cost));
    }
    dijkstra(start);
    for(int i=1; i<=V; i++){
        if(dist[i]>=inf)
            printf("INF\n");
        else
            printf("%d\n",dist[i]);
    }
}

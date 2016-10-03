#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
vector < pair < int , int > > v[1001];
int dist[1001];
int visited[1001];
int inf=1000000000;
priority_queue < pair < int , int > > pq;
void dijkstra(int start){
    dist[start]=0;
    pq.push(make_pair(0,start)); // pair<거리,노드> 거리가 작은 순서대로 정렬
    while(!pq.empty()){
        pair < int , int > tmp = pq.top();
        pq.pop();
        int c= tmp.second;
        if(visited[c] == 1)
            continue;
        visited[c]=1;
        for(int j=0; j<v[c].size(); j++){
            int n=v[c][j].first;
            if(dist[n] > dist[c] + v[c][j].second){
                dist[n]=dist[c] + v[c][j].second;
                pq.push(make_pair(-dist[n],n));//max_heap에 넣으니까.
            }
        }
    }
}
int main(){
    int n,m;
    int U,V,cost;
    int start,end;
    scanf("%d %d",&n,&m);
    fill(dist,dist+n+1,inf);
    for(int i=0; i<m; i++){
        scanf("%d %d %d",&U,&V,&cost);
        v[U].push_back(make_pair(V,cost));
    }
    scanf("%d %d",&start,&end);
    dijkstra(start);
    printf("%d\n",dist[end]);
}

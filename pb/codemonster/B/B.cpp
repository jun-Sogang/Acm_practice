#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
typedef long long ll;
int dist[1001];
vector < pair < int , int > > v[1001];
bool visited[10001];
int edge_min[10001];
pair < int, int > dijkstra(int s, int t){
    priority_queue < pair < int , int > > pq;
    dist[s]=0;
    pq.push(make_pair(0,s));
    while(!pq.empty()){
        int c= pq.top().second;
        pq.pop();
        if(visited[c]==true)
            continue;
        visited[c]=true;
        for(int j=0; j<v[c].size(); j++){
            int n=v[c][j].first;
            int Min=v[c][j].second;
            if(dist[n]<dist[c]+v[c][j].second){
                dist[n] =dist[c]+v[c][j].second;
                pq.push(make_pair(dist[n],n));
                edge_min[n]=min(Min,edge_min[c]);
                
            }
            else if(dist[n]==dist[c]+v[c][j].second){
                edge_min[n]=min(edge_min[n],min(Min,edge_min[c]));
            }
        }
    }
    pair < int , int > ans = make_pair(dist[t],edge_min[t]);
    return ans;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m,q,s,t;
        int U,V,cost;
        int Max=0;
        int ans=1000000000;
        pair < int , int > result;
        fill(edge_min,edge_min+10000,1000000000);
        fill(visited,visited+10000,false);
        for(int i=0; i<1000; i++)
            v[i].clear();
        scanf("%d %d",&n,&m);
        fill(dist,dist+n+1,0);
        for(int i=0; i<m; i++){
            scanf("%d %d %d",&U,&V,&cost);
            v[U].push_back(make_pair(V,cost));
        }
        scanf("%d",&q);
        for(int i=0; i<q; i++){
            scanf("%d %d",&s,&t);
            result=dijkstra(s,t);
            if(result.first >=Max){             //가장 긴거
                ans=min(ans,result.second);     //second : 최솟값
                Max=result.first;
            }
        }
        printf("%d\n",ans);
    }
}

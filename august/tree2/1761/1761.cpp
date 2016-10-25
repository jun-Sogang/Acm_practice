#include <cstdio>
#include <vector>
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
vector < pair < int , int > > v[40002];
vector < pair < int , int > > from_to;
int dist[40002];
int depth[40002];
int pre_node[40002];
int find_dist(int from, int to){
    int a=from;
    int b=to;
    int a_sum=0;
    int b_sum=0;
    while(a!=b){
        if(depth[a]>depth[b]){
            a_sum+=dist[a]; 
            a=pre_node[a];
        }
        else if(depth[a]<depth[b]){
            b_sum+=dist[b];
            b=pre_node[b];
        }
        else{
            a_sum+=dist[a];
            b_sum+=dist[b];
            a=pre_node[a];
            b=pre_node[b];
        }
    }
    return a_sum+b_sum;
}
int main(){
    int n,m;
    cin >> n;
    for(int i=0; i<n-1; i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        v[a].push_back(make_pair(b,c));
        v[b].push_back(make_pair(a,c));
    }
    cin >> m;
    for(int i=0; i<m; i++){
        int a,b;
        scanf("%d %d",&a,&b);
        from_to.push_back(make_pair(a,b));
    }
    //depth setting + pre_node setting
    bool visit[n];
    memset(visit,false,sizeof(visit));
    pre_node[1]=-1;
    depth[1]=0;
    visit[1]=true;
    queue < int > q;
    q.push(1);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int i=0; i<v[node].size(); i++){
            int next=v[node][i].first;
            if(visit[next]!=true){
                depth[next]=depth[node]+1;
                pre_node[next]=node;
                q.push(next);
                dist[next]=v[node][i].second;
                visit[next]=true;
            }
        }
    }
    for(int i=0; i<m; i++){
        printf("%d\n",find_dist(from_to[i].first,from_to[i].second));
    }
}

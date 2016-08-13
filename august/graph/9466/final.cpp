#include <cstdio>
#include <vector>
using namespace std;
int visited[1001];
int cnt=1;
bool cycle=false;
int cycle_vertex=0;
vector < vector < int > > v;
void dfs(int V){
    visited[V]=cnt++;
    for(int i=0; i<(int)v[V].size(); i++){
        if(visited[v[V][i]]==-1){
            if(visited[V]!=-1){
                cycle_vertex++;
            }
            break;
        }
        if(visited[v[V][i]]==-2){
            cycle_vertex++;
            break;
        }
        if(visited[v[V][i]]==0)
            dfs(v[V][i]);
        if(visited[v[V][i]]==1){
            cycle=true;
        }
    }
    if(cycle)
        visited[V]=-1;
    else
        visited[V]=-2;
}
int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        int t,temp;
        scanf("%d",&t);
        v.resize(t+1);
        for(int i=1; i<=t; i++){
            scanf("%d",&temp);
            v[i].push_back(temp);
        }
        for(int i=1; i<=t; i++){
            dfs(i);
            cnt=1;
            cycle=false;
        }
        printf("%d\n",cycle_vertex);    
    }
}

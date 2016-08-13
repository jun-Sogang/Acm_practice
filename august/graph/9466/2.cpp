#include <cstdio>
#include <vector>
using namespace std;
vector < vector < int > > v;
vector < int > check;
bool visit[1001];
void dfs(int V){
    visit[V]=true;
    check.push_back(V);
    for(int i=0; i<(int)v[V].size(); i++){
        if(visit[v[V][i]]!=true)
            dfs(v[V][i]);
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int b;
        scanf("%d",&n);
        v.resize(n+1);
        for(int i=1; i<=n; i++){
            int temp;
            scanf("%d",&temp);
            v[i].push_back(temp);
        }
        for(int i=1; i<=n; i++)
            dfs(i);
    }
}

#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector <  vector < pair < int , int > > > v;
int visit[100001];
int Max=0;
int vertex=0;
void dfs(int V,int sum){
    visit[V]=true;
    for(int i=0; i<(int)v[V].size();i++){
        if(visit[v[V][i].first]!=true){
            sum+=v[V][i].second;
            dfs(v[V][i].first,sum);
            if(Max<sum){
                Max=sum;
                vertex=v[V][i].first;
            }
            sum-=v[V][i].second;
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    v.resize(n+1);
    for(int i=0; i<n-1; i++){
        int V;
        int a,length;
        scanf("%d",&V);
        scanf("%d %d",&a,&length);
        v[V].push_back(make_pair(a,length));
        v[a].push_back(make_pair(V,length));
    }
    dfs(1,0);
    Max=0;
    for(int i=1; i<=n; i++)
        visit[i]=false;
    dfs(vertex,0);
    printf("%d\n",Max);
}

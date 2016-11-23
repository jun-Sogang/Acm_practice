#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 100001;
vector < pair < int , int > > v[MAX];
// v[a] = (b,c)    a->b 로 cost : c
int depth[MAX];
int parent[MAX][18];
int least[MAX][18];
int largest[MAX][18];
void make_parent_by_DFS(int cur){
    for(int i=0; i<v[cur].size(); i++){
        int next = v[cur][i].first;
        if(depth[next] == -1){
            depth[next] = depth[cur]+1;
            parent[next][0] = cur;
            least[next][0]=v[cur][i].second;
            largest[next][0]=v[cur][i].second;
            make_parent_by_DFS(next);
        }
    }
}
void query(int d,int e){
    int ans_largest=-1;
    int ans_least=1000001;
    int u=d;
    int v=e;
    if(depth[u] < depth[v])
        swap(u,v);
    int diff = depth[u]-depth[v];
    for(int i=0; diff; i++){
        if(diff%2){
            ans_least = min(ans_least,least[u][i]);
            ans_largest = max(ans_largest,largest[u][i]);
            u= parent[u][i];
        }
        diff/=2;
    }
    if(u != v){
        for(int j = 18-1; j>=0; --j){
            if(parent[u][j] != -1 && parent[u][j] != parent[v][j]){
                ans_least = min(ans_least, min(least[u][j],least[v][j]));
                ans_largest = max(ans_largest,max(largest[u][j],largest[v][j]));
				u=parent[u][j];
                v=parent[v][j];
            }
        }
        ans_least = min(ans_least,min(least[u][0],least[v][0]));
        ans_largest = max(ans_largest,max(largest[u][0],largest[v][0]));
    }
    printf("%d %d\n",ans_least, ans_largest);
}
int main(){
    memset(parent,-1,sizeof(parent));
    memset(depth,-1,sizeof(depth));
    for(int i=0; i<MAX; i++){
        for(int j=0; j<18; j++)
            least[i][j]=1000001;
    }
    memset(largest,-1,sizeof(largest));
    int n,k;
    cin >> n;
    for(int i=0; i<n-1; i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        v[a].push_back(make_pair(b,c));
        v[b].push_back(make_pair(a,c));
    }
    depth[1]=0;
    make_parent_by_DFS(1);
    for(int j=0; j<18-1; ++j){
        for(int i=1; i<=n; ++i){
            if(parent[i][j] != -1){
                parent[i][j+1] = parent[parent[i][j]][j];
                least[i][j+1] = min(least[i][j],least[parent[i][j]][j]);
                largest[i][j+1] = max(largest[i][j],largest[parent[i][j]][j]);

            }
        }
    }
    cin >> k;
    for(int i=0; i<k; i++){
        int d,e;
        scanf("%d %d",&d,&e);
        query(d,e);
    }

}

#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
vector < vector < int > > v;
bool visit[100001];
int parent[100001];
int main(){
    int n;
    scanf("%d",&n);
    v.resize(n+1);
    for(int i=0; i<n-1; i++){
        int a,b;
        scanf("%d %d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    queue < int > que;
    que.push(1);
    visit[1]=true;
    parent[1]=-1;
    while(!que.empty()){
        int x=que.front();
        que.pop();
        for(int i=0; i<(int)v[x].size();i++){
            if(visit[v[x][i]]!=true){
                que.push(v[x][i]);
                visit[v[x][i]]=true;
                parent[v[x][i]]=x;
            }
        }
    }
    for(int i=2; i<=n; i++){
        printf("%d\n",parent[i]);
    }
}

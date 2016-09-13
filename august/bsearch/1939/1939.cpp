#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
vector < vector < pair < int , int > > > g;// g[a].first : 도착점
                                           // g[a].second : 가중치
int visit[100001],ge1,ge2,mid;
bool go(int ge1,int mid){
    if(visit[ge1])
        return false;
    visit[ge1]=true;
    if(ge1==ge2)
        return true;
    for(int i=0; i<g[ge1].size(); i++){
        int next=g[ge1][i].first;
        int cost=g[ge1][i].second;
        if(cost>=mid)
            if(go(next,mid))
                return true;
    }
    return false;
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    g.resize(n+1);
    for(int i=0; i<m; i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        g[a].push_back(make_pair(b,c));
        g[b].push_back(make_pair(a,c));
    }
    scanf("%d %d",&ge1,&ge2);
    int left=1, right=1000000000;
    int ans=0;
    while(left <= right){
        mid =left+(right-left)/2;
        memset(visit,false,sizeof(visit));
        if(go(ge1,mid)){
            ans=mid;
            left = mid+1;
        }
        else
            right= mid-1;
    }
    printf("%d\n",ans);
}

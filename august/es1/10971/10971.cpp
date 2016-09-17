#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector < int > v;
int ans=2147483647;
int cost[11][11];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0; i<n ;i++)
        for(int j=0; j<n; j++)
            scanf("%d",&cost[i][j]);
    for(int i=0; i<n; i++)
        v.push_back(i);
    do{
        int query_cost=0;
        bool flag=true;
        for(int i=0; i<n-1; i++)
            if(cost[v[i]][v[i+1]] == 0 )
                flag=false;
        if(flag && cost[v[n-1]][v[0]] != 0){
            for(int i=0; i<n-1; i++)
                query_cost+=cost[v[i]][v[i+1]];
            query_cost+=cost[v[n-1]][v[0]];
        ans=min(ans,query_cost);
        }
    }while(next_permutation(v.begin(),v.end()));
    printf("%d\n",ans);
}

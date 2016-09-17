#include <cstdio>
#include <vector>
#include <algorithm>
#include <vector>
using namespace std;
vector < pair < int int > > v[100001];//v[출발].(비용,도착)
int main(){
    int n,m;
    scanf("%d",&n);
    scanf("%d",&m);
    for(int i=0; i<m; i++){
        int from,to,cost;
        scanf("%d %d %d",&from,&to,&cost);
        v[from].push_back(make_pair(cost,to));
    }
    int from,to;
    scanf("%d %d",&from,&to);
}

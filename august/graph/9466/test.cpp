#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
vector  < int > v[100003];
int visited[100003];
int cn = 1;
int cycle_vertex = 0;
void dfs(int V)
{
    visited[V] = cn++;
    for (int i = 0; i < (int)v[V].size(); i++) {
        if (visited[v[V][i] ] == 0)
            dfs(v[V][i]);
        else if(visited[v[V][i]]!=1){
            cycle_vertex++;
            break;
        }
    }
}
int main()
{
    int t,n,input;
    scanf("%d%*c", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &input);
            v[i].push_back(input);
        }
        for (int i = 1; i <= n; i++) {
            dfs(i);
            cn = 1;
            memset(visited,false,sizeof(visited));
        }
        printf("%d\n", cycle_vertex);
        cycle_vertex = 0;
        for (int i = 0; i <= n; i++)
            v[i].clear();
    }
}

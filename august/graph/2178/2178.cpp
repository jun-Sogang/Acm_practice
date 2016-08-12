#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int map[101][101];
int visit[101][101];
int cnt=1;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int n,m;
int bfs(int i,int j){
    queue < pair < int , int > > que;
    que.push(make_pair(j,i));
    visit[j][i]=cnt++;
    while(!que.empty()){
        int y=que.front().first;
        int x=que.front().second;
        que.pop();
        for(int l=0; l<4; l++){
            int nx=x+dx[l];
            int ny=y+dy[l];
            if(nx>=0 && nx<m && ny>=0 &&ny<n && map[ny][nx]==1 && visit[ny][nx]==0){
                que.push(make_pair(ny,nx));
                visit[ny][nx]=visit[y][x]+1;
            }
            if(visit[n-1][m-1]!=0)
                return visit[n-1][m-1];
        }
    }
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0; i<n; i++)
        for(int j=0; j<m ;j++)
            scanf("%1d",&map[i][j]);
    printf("%d\n",bfs(0,0));
}

#include <cstdio> 
#include <algorithm>
#include <queue>
using namespace std;
int a[101][101];
int ans[101][101];
int group[101][101];
int dx[4] = {0,1,-1,0};
int dy[4] = {1,-0,0,-1};
int n;
queue < pair < int, int > > q;
void bfs(int i,int j){
    while(!q.empty()){
        int x= q.front().first;
        int y= q.front().second;
        q.pop();
        for(int l=0; l<4; l++){
            int nx=x+dx[l];
            int ny=y+dy[l];
            if(nx>=0 && nx<n && ny>=0 && ny<n && ans[nx][ny]==-1){
                q.push(make_pair(nx,ny));
                ans[nx][ny]=ans[x][y]+1;
                group[nx][ny]=group[x][y];
            }
        }
    }
}
void grouping(int i,int j,int num){
    queue < pair < int , int > > que;
    que.push(make_pair(i,j));
    group[i][j]=num;
    while(!que.empty()){
        int x= que.front().first;
        int y= que.front().second;
        que.pop();
        for(int l=0; l<4; l++){
            int nx=x+dx[l];
            int ny=y+dy[l];
            if(nx>=0 && nx<n && ny>=0 && ny<n && a[nx][ny]==1 && group[nx][ny]==0){
                que.push(make_pair(nx,ny));
				group[nx][ny] = num;
            }
        }
    }
}

int main(){
    int group_num=1,MIN=1000;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
			ans[i][j] = -1;
		}
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(a[i][j]==1 && group[i][j]==0){
                grouping(i,j,group_num++);
                }
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			if (a[i][j] == 1)
			{
				ans[i][j] = 1;
				q.push(make_pair(i, j));
			}
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(a[i][j]==1)
                bfs(i,j);

    for(int i=0; i<n; i++)
        for(int j=0; j<n ; j++)
            for(int k=0; k<2; k++){
                int nx = i+dx[k];
                int ny = j+dy[k];
                if(group[nx][ny] != group[i][j] && nx>=0 && nx<n && ny>=0 && ny<n)
                    MIN=min(MIN,ans[i][j]+ans[nx][ny]);
            }
    printf("%d\n",MIN-2);
                
                
                
}

#include <cstdio>
#include <queue>
using namespace std;

int a[101][101];
int continent[101][101];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%d",&a[i][j]);
    int cnt=0;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            if(a[i][j]==1 && continent[i][j] ==0){
                continent[i][j]=++cnt;
                queue < pair < int , int > > q;
                q.push(make_pair(i,j));
                while(!q.empty()){
                    int x= q.front().first;
                    int y= q.front().second;
                    q.pop();
                    for(int l=0; l<4; l++){
                        int nx= x+dx[l];
                        int ny= y+dy[l];
                        if(nx>=0 && nx<n && ny>=0 && ny<n && a[i][j]==1 && continent[i][j]==0){
                            continent[i][j]=cnt;
                            q.push(make_pair(nx,ny));
                        }

                    }
                   
                }
            }
        }
    
         

}

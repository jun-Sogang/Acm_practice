#include <cstdio>
#include <iostream>
using namespace std;
int a[51][51];
int ans[51][51];
void change(int i,int j){
    for(int m=i; m<i+3; m++)
        for(int n=j; n<j+3; n++){
            a[m][n]=1-a[m][n];
        }
}
int main(){
    int n,m;
    bool flag=true;
    cin >> n >> m;
    for(int i=0; i<n ;i++)
        for(int j=0; j<m; j++)
            scanf("%1d",&a[i][j]);
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf("%1d",&ans[i][j]);

    if(n <3 || m<3){
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(a[i][j] != ans[i][j]){
                    flag=false;
                    break;
                }
        if(flag){
            cout << 0;
            return 0;
        }
        else{
            cout << -1;
            return 0;
        }
    }
    int count=0;
    for(int i=0; i<n; i++)
        for(int j=0; j<m ;j++){
            if(a[i][j]!=ans[i][j]){
                if(i>n-3 || j>m-3){
                    cout << -1;
                    return 0;
                }
                change(i,j);
                count++;
            }
        }
    cout << count << endl;
}


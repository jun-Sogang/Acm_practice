#include <cstdio>
#include <iostream>
using namespace std;
int n;
bool check_col[20];
bool check_left[100];
bool check_right[100];
bool check(int row,int col){
    if(check_col[col] || check_left[row+col] || check_right[row-col+n-1])
        return false;
    return true;
}
int calc(int row){
    if(row==n)
        return 1;
    int ans=0;
    for(int col=0; col<n; col++){
        if(check(row,col)){
            check_col[col]=true;
            check_left[row+col]=true;
            check_right[row-col+n-1]=true;
            ans+=calc(row+1);
            check_col[col]=false;
            check_left[row+col]=false;
            check_right[row-col+n-1]=false;
        }
    }
    return ans;
}
int main(){
    scanf("%d",&n);
    cout << calc(0);
    puts("");
}

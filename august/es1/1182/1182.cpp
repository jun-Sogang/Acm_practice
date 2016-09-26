#include <cstdio>
#include <iostream>
using namespace std;
int a[21];
int check[21];
int ans=0;
int n,s;
void go(){
    int temp=0;
    for(int i=0; i<n; i++){
        if(check[i]==1)
            temp+=a[i];
    }
    if(temp==s)
        ans++;
}
void next_binary(int index){ // 시작은 마지막 index 할 것
    if(check[index]==0)
        check[index]=1;
    else{
        check[index]=0;
        next_binary(index-1);
    }
}
int main(){
    int two_s=1;
    cin >> n >> s;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<n; i++)
        two_s*=2;
    for(int i=1; i<two_s; i++){
        next_binary(n-1);
        go();
    }
    printf("%d\n",ans);
}

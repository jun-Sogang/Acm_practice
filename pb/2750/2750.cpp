#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector < int > v;
int main(){
    int n,input;
    scanf("%d",&n);
    v.resize(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    for(int i=0; i<n; i++){
        cout << v[i];
        puts("");
    }
}

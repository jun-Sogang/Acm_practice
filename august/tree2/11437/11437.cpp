#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
queue < int > q;
vector < int > v[50005];
int depth[50005];
bool visit[50005];
int ances[50005];
int lsa(int a, int b){
    while(depth[a]!=depth[b]){
        if(depth[a] > depth[b]){
            a=ances[a];
        }
        else{
            b=ances[b];
        }
        21
    }
    while(a!=b){
        a=ances[a];
        b=ances[b];
    }
    return a;;
};
int main(){
    int n;
    cin >> n;
    for(int i=0; i<n-1; i++){
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    depth[1]=0;
    visit[1]=true;
    ances[1]=-1;
    q.push(1);
    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        for(int i=0; i<v[tmp].size(); i++){
            if(visit[v[tmp][i]]!=true){
                visit[v[tmp][i]]=true;
                q.push(v[tmp][i]);
                depth[v[tmp][i]]=depth[tmp]+1;
                ances[v[tmp][i]]=tmp;
            }
        }
    }
    int m;
    cin >> m;
    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        cout <<lsa(a,b) << "\n";
    }
};

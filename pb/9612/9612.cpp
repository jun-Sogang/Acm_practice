#include <cstdio>
#include <iostream>
#include <string>
#include <map>
using namespace std;
map < string , int > m;
int main(){
    int n,max=-1;
    string search;
    cin >> n;
    for(int i=0; i<n; i++){
        string temp;
        cin >> temp;
        m[temp]++;
        if(max<=m[temp]){
            if(max==m[temp] && temp <= search)
                continue;
            max=m[temp];
            search=temp;
        }
    }
    cout << search << " " << max <<endl;
}

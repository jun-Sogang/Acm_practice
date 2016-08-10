#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
vector < string > v;
int main(){
    string a;
    cin >> a ;
    int size=a.size();
    for(int i=0; i<size; i++)
        v.push_back(a.substr(i,size));
    sort(v.begin(),v.end());
    for(int i=0; i<size; i++)
        cout << v[i] << endl;
}

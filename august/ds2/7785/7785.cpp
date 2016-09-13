#include <cstdio>
#include <iostream>
#include <string>
#include <set>
#include <iterator>
#include <algorithm>
using namespace std;
set < string > s;
int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        string name,in_out;
        cin >> name >> in_out;
        if(in_out == "enter"){
            s.insert(name);
        }
        else
            s.erase(s.find(name));
    }
     
    set < string >::reverse_iterator it;
    for(it = s.rbegin();it!=s.rend();++it)
        cout << *it << endl;
}

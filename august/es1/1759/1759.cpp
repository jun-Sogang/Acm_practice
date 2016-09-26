#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
char a[16];
vector < int > check;
vector < string > v;
int main(){
    int l,c;
    cin >> l >> c;
    for(int i=0; i<c; i++){
        cin >> a[i];
    }
    sort(a,a+c);
    for(int i=0; i<c-l; i++)
        check.push_back(0);
    for(int i=0; i<l; i++)
        check.push_back(1);
    do{
        string temp;
        int m=0;
        int n=0;
        for(int i=0; i<c; i++){
            if(check[i]==1){
                temp+=a[i];
                if(a[i]== 'a' || a[i] == 'i' || a[i] == 'e' || a[i] == 'u' || a[i] == 'o')
                    m++;
                else
                    n++;
            }
        }
        if(m>=1 && n>=2){
            v.push_back(temp);
        }
    }while(next_permutation(check.begin(),check.end()));
    sort(v.begin(),v.end());
    for(int i=0; i<v.size(); i++){
        cout << v[i];
        puts("");
    }
}

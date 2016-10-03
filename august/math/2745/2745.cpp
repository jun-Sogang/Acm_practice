#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
int main(){
    int b;
    int ans=0;
    string n;
    string reverse_n;
    cin >> n >> b;
    for(int i=0; i<n.size(); i++){
        reverse_n+=n[n.size()-1-i];
    }
    for(int i=0; i<reverse_n.size(); i++){
        int index=1;
        for(int j=0; j<i; j++)
            index*=b;
        if(reverse_n[i]<='9' && reverse_n[i]>=0)
            ans+=(reverse_n[i]-48)*index;
        else
            ans+=(reverse_n[i]-55)*index;
    }
    printf("%d\n",ans);

    

}

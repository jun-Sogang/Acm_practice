#include <iostream>
using namespace std;
int main(){
    int n;
    int count=2;
    cin >> n;
    while(n>1){
        if(n%count == 0){
            cout << count<<"\n";
            n/=count;
        }
        else
            count++;
    }
};

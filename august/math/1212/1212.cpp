#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
string init[8]={"0","1","10","11","100","101","110","111"};
string num[8]={"000","001","010","011","100","101","110","111"};
int main(){
    string input;
    cin >> input;
    cout << init[input[0]-48];
    for(int i=1; i<input.size(); i++){
        cout << num[input[i]-48];
    }
    puts("");
}

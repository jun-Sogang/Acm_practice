#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
int dex[3] = {4,2,1};
int main(){
    string input;
    string pre;
    string post;
    cin >> input;
    pre=input.substr(0,input.size()%3);
    post=input.substr(input.size()%3,input.size()-input.size()%3);

    if(!pre.empty()){
       if(pre.size()==1)
           printf("%d",pre[0]-48);
       else{
           printf("%d",(pre[0]-48)*2+(pre[1]-48));
       }
    }
    int temp=0;
    for(int i=0; i<post.size(); i++){
        temp+=(post[i]-48)*dex[i%3];
        if(i%3==2){
            printf("%d",temp);
            temp=0;
        }
    }
    puts("");

}

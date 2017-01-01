#include <string>
#include <iostream>
#include <queue>
#include <map>
using namespace std;
int ans=0;
map < int, int > visit;
int process(int map){
    queue < pair < int, int > > q;
    q.push(make_pair(map,0));
    visit[(map)] = 1;
    while(!q.empty()){
        string now = to_string(q.front().first);
        int now_ans = q.front().second;
        int zero = now.find('9');
        q.pop();

        if(now == "123456789"){
            return now_ans;
        }

        if(zero%3 != 0){
            swap(now[zero], now[zero-1]);
            if(visit[stoi(now)] != 1){
                visit[stoi(now)] = 1;
                q.push(make_pair(stoi(now),now_ans+1));
            }
            swap(now[zero], now[zero-1]);
        }
        if(zero/3 != 0){
            swap(now[zero], now[zero-3]);
            if(visit[stoi(now)] != 1){
                visit[stoi(now)] = 1;
                q.push(make_pair(stoi(now), now_ans+1));
            }
            swap(now[zero], now[zero-3]);
        }
        if(zero%3 != 2){
            swap(now[zero], now[zero+1]);
            if(visit[stoi(now)] != 1){
                visit[stoi(now)] = 1;
                q.push(make_pair(stoi(now), now_ans+1));
            }
            swap(now[zero], now[zero+1]);
            //오른쪽가능
        }
        if(zero/3 != 2){
            swap(now[zero], now[zero+3]);
            if(visit[stoi(now)] != 1){
                visit[stoi(now)] = 1;
                q.push(make_pair(stoi(now), now_ans+1));
            }
            swap(now[zero], now[zero+3]);
            //아래 가능
        }

    }
    return -1;
}

int main(){
    string input;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            string temp;
            cin >> temp;
            if(temp[0] == '0'){
                temp='9';
            }
            input+=temp;
        }
    }
    cout << process(stoi(input));
}

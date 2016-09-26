#include <cstdio>
#include <queue>
#include <functional>
#include <vector>
using namespace std;
priority_queue < int > maxQ;
priority_queue < int , vector < int > , greater < int > > minQ;
int main(){
    int n,count=0;
    scanf("%d",&n);
    while(n--){
        int temp;
        scanf("%d",&temp);
        count++;
        if(count==1){
            maxQ.push(temp);
            printf("%d\n",maxQ.top());
        }
        else if(count&1){ // 홀수 판별
            if(minQ.top() > temp)
                maxQ.push(temp);
            else{
                maxQ.push(minQ.top());
                minQ.pop();
                minQ.push(temp);
            }
            printf("%d\n",maxQ.top());
        }
        else{
            if(maxQ.top() < temp)
                minQ.push(temp);
            else{
                maxQ.push(temp);
                minQ.push(maxQ.top());
                maxQ.pop();
            }
            printf("%d\n",maxQ.top());
        }
    }
}


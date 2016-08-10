#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
vector < int > v;
priority_queue < int, vector < int > , greater < int > > a;
int main(){
    int n,m;
    int input;
    scanf("%d %d",&n,&m);
    for(int i=0; i<n ;i++){
        scanf("%d",&input);
        a.push(input);
    }
    for(int i=1; i<m; i++){
        a.pop();
    }
    printf("%d\n",a.top());
}

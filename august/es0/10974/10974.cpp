#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector < int > p;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        p.push_back(i);
        printf("%d ",i);
    }
    puts("");
    while(next_permutation(p.begin(),p.end())){
        for(int i=0; i<p.size(); i++)
            printf("%d ",p[i]);
        puts("");
    }
}

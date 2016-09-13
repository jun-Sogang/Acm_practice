#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector < int > p;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        int temp;
        scanf("%d",&temp);
        p.push_back(temp);
    }
    if(prev_permutation(p.begin(),p.end())){
        for(int i=0; i<p.size(); i++)
            printf("%d ",p[i]);
    }
    else{
        printf("-1");
    }
    puts("");
}

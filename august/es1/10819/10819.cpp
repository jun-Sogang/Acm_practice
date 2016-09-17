#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector < int > v;
int n;
int MAX=-1;
int abs(int input){
    if(input<0)
        input*=-1;
    return input;
}
int go(){
    int ans=0;
    for(int i=0; i<n-1; i++){
        ans+=abs(v[i]-v[i+1]);
    }
    return ans;
}
int main(){
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        int temp;
        scanf("%d",&temp);
        v.push_back(temp);
    }
    sort(v.begin(),v.end());
    do{
        MAX=max(MAX,go());
    }while(next_permutation(v.begin(),v.end()));
    printf("%d\n",MAX);
}

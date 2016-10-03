#include <cstdio>
#include <vector>
using namespace std;
vector < int > v;
int main(){
    int n;
    char a[102];
    scanf("%d %s",&n,a);
    int count=0;
    int black_count=0;
    for(int i=0; i<n; i++){
        if(a[i]=='B'){
            count++;
            black_count=0;
            for(int j=i; j<n; j++){
                black_count++;
                if(a[j]=='W' || j==n-1){
                    if(a[j]=='W')
                        black_count--;
                    v.push_back(black_count);
                    i=j;
                    j=n;
                }
            }
        }
    }
    printf("%d\n",count);
    if(!v.empty()){
        for(int i=0; i<v.size(); i++)
            printf("%d ",v[i]);
        puts("");
    }
}

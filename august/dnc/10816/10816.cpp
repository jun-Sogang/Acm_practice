#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);

    vector < int > a(n);
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
    sort(a.begin(),a.end());
    int m;
    scanf("%d",&m);
    for(int i=0; i<m; i++){
        int num;
        scanf("%d",&num);
        auto l = lower_bound(a.begin(),a.end(),num);
        auto r = upper_bound(a.begin(),a.end(),num);
        printf("%d ",r-l);
    }
    puts("");
    return 0;
}

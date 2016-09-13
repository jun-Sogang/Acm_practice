#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
ll a[10001];
int n,k;
bool check(ll mid){
    int cnt=0;
    for(int i=0; i<k; i++){
        cnt+=a[i]/mid;
    }
    return cnt >= n;
}
int main(){
    scanf("%d %d",&k,&n);
    for(int i=0; i<k; i++)
        scanf("%lld",&a[i]);
    sort(a,a+k);
    ll l=1;
    ll ans=0;
    ll r=a[k-1];
    while(l<=r){
        ll mid= (r+l)/2;
        if(check(mid)){
            if(ans<mid){
                ans=mid;
            }
            l=mid+1;
        }
        else
            r=mid-1;
    }
    printf("%lld\n",ans);
}

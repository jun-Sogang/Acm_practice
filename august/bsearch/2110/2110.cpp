#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
vector < ll > v;
int n,c;
bool check(ll mid){
    int count=1;
    ll first=v[0];
    for(int i=1; i<n; i++){
        if(v[i]-first>=mid){
            first=v[i];
            count++;
        }
    }
    return count >= c;
}
int main(){
    scanf("%d %d", &n, &c);
    for(int i=0; i<n; i++){
        ll temp;
        scanf("%lld",&temp);
        v.push_back(temp);
    }
    sort(v.begin(),v.end());
    
    ll l=0;
    ll r=v.back();
    ll ans=0;
    while(l<=r){
        ll mid=(r+l)/2;
        if(check(mid)){
            ans=max(ans,mid);
            l=mid+1;
        }
        else
            r=mid-1;

    }
    printf("%lld\n",ans);
}

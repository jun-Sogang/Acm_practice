#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
int a[10001];
int zero=0;
int main(){
    int n,temp;
    int minus=0;
    int plus=0;
    ll ans=0;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%d",&temp);
        a[i]=temp;
        if(temp>0)
            plus++;
        else if(temp<0)
            minus++;
        else
            zero++;
    }
    sort(a,a+n);
    for(int i=0; ;i++){
        if(plus>=2){
            if(a[n-1-i-1]==1 || a[n-1-i]==1){
                ans+=a[n-1-i]+a[n-1-i-1];
                i++;
                plus-=2;
            }
            else{
                ans+=a[n-1-i]*a[n-1-i-1];
                i++;
                plus-=2;
            }
        }
        else if(plus==0)
            break;
        else{
            ans+=a[n-1-i];
            break;
        }
    }
    for(int i=0; ; i++){
        if(minus>=2){
            ans+=a[i]*a[i+1];
            i++;
            minus-=2;
        }
        else if(minus==0)
            break;
        else
        {
            if(zero>0)
                ;
            else
                ans+=a[i];
            break;
        }
    }
    printf("%lld\n",ans);
}

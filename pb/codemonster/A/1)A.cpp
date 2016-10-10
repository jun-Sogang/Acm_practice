#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
ll bitset_OneCounter(ll n){
    ll count=0;
    while(n){
        count++;
        n&=(n-1);
    }
    return count;
}
ll count(ll n){
    ll num=n-1;
    ll ans=n-1;
    while(num>0){
        num/=2;
        ans+=num;
    }
    return ans;
}
int main(){
    int t;
	FILE *fp = fopen("input.txt", "r");
	FILE *fp2 = fopen("output.txt", "wt+");
	fscanf_s(fp,"%d",&t);
    while(t--){
        ll from,to;
        ll ans=0;
        fscanf_s(fp,"%lld %lld",&from,&to);
        for(ll i=from; i<to; i++){
            ll temp;
            if((i&(i-1))==0 && i*2-1<=to){
                ans+=count(i);
                i=i*2-2;
            }
            else{
                temp= i ^ (i+1);
                ans+=bitset_OneCounter(temp);
            }
        }
        fprintf_s(fp2,"%lld\n",ans);
    }
	fclose(fp);
	fclose(fp2);
}

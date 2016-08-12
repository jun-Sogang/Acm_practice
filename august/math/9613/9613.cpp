#include <cstdio>
#include <algorithm>
using namespace std;
int gcd(int a,int b){
    if(a<b)
        swap(a,b);
    if(a*b==0)
        return a+b;
    else
        return gcd(b,a%b);

}
int a[101];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        long long sum=0;
        scanf("%d",&n);
        for(int i=0; i<n; i++)
            scanf("%d",&a[i]);
        for(int i=0; i<n; i++)
            for(int j=i+1; j<n; j++)
                sum+=gcd(a[i],a[j]);
        printf("%lld\n",sum);
    }
    
}

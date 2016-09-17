#include <cstdio>
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int p,m,f,c;
        long long cnt=0;
        long long coupon;
        int a,b;
        scanf("%d %d %d %d",&p,&m,&f,&c);
        a=m/p+m/p*c/f;
        b=a;
        coupon=m/p*c/f*c;
        while(coupon/f){
            b+=coupon/f;
            coupon=coupon/f+coupon/f*c;
        }
        printf("%d\n",b-a);
    }
}

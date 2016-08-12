#include <cstdio>
#include <algorithm>
using namespace std;
int gcd(int a, int b){
    if(a<b)
        swap(a,b);
    if(a*b==0)
        return a+b;
    else
        return gcd(b,a%b);
}
int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        int a,b;
        scanf("%d %d",&a,&b);
        printf("%d\n",a*b/gcd(a,b));
    }
}

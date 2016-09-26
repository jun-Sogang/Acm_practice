#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int a[5000000];
int main() {
    int n,k;
    scanf("%d %d",&n,&k);
    k--;
    for (int i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    nth_element(a,a+k,a+n);
    printf("%d\n",a[k]);
    return 0;
}
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
map < ll , int > m;
int main()
{
    int n;
    ll temp;
    int Max=0;
    ll index=-1;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%lld",&temp);
        m[temp]++;
        if(index==-1){
            index=temp;
            Max=m[temp];
        }
            
        if(m[temp] > Max){
            Max=m[temp];
            index=temp;
        }
        else if(m[temp] == Max && temp < index){
            index=temp;
        }
    }
    printf("%lld\n",index);
}

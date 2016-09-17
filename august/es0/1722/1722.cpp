#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector < int > p;
vector < int > check;
bool flag[21];
long long factorial(int n){
    return (n==1 || n==0) ? 1 : factorial(n-1)*n;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        p.push_back(i);
    int k;
    scanf("%d",&k);
    if(k==1){
        long long m;
        scanf("%lld",&m);
        for(int i=1; i<=n; i++){
            long long temp=factorial(n-i);
            if(m>temp){
                int count=0;
                while(m>temp){
                    count++;
                    m-=temp;
                }
                int flag_count=0;
                for(int j=1; j<=n; j++){
                    if(flag[j]==false)
                        flag_count++;
                    if(count+1==flag_count){
                        flag[j]=true;
                        printf("%d ",j);
                        break;
                    }
                }
            }
            else{
                for(int j=1; j<=n; j++){
                    if(flag[j]==false){
                        printf("%d ",j);
                        flag[j]=true;
                        break;
                    }
                }
            }
 
        }
    }
    else{
        for(int i=0; i<n; i++){
            int temp;
            scanf("%d",&temp);
            check.push_back(temp);
        }
        long long ans=1;
        for(int i=0; i<n; i++){
            int plus=0;
            for(int j=1; i<=n; j++){
 
                if(flag[j]==false && check[i] != j)
                    plus++;
                if(check[i] == j)
                    break;
 
            }
            ans+=factorial(n-i-1)*(plus);
            flag[check[i]]=true;
        }
        printf("%lld\n",ans);   
    }
}
#include <cstdio>
#include <string>
#define mod 1000000
using namespace std;
int dp[5005];
int main(){
    char secret[5005];
    string a;
    scanf("%s",secret);
    a=secret;
    a=" "+a;
    int size=a.size();
    dp[0]=1;
    for(int i=1; i<=size; i++){
        int temp=a[i]-'0';
        if(temp>=1 && temp<=9){
            dp[i]+=dp[i-1];
            dp[i]%=mod;
        }
        if(i==1)
            continue;
        temp=(dp[i-1]-'0')*10+dp[i]-'0';
        if(temp >= 10 && temp <= 26){
            dp[i]+=dp[i-2];
            dp[i]%=mod;
        }
    }
    printf("%d\n",dp[size]);
}

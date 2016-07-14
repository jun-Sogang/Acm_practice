#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    int temp_n,temp_a,temp_b;
    int balloon_a,ballon_b;
    int ans=0;
    vector < pair < int , pair < int, int > > > v;

    scanf("%d %d %d",&n,&ballon_a,&ballon_b);
    v.resize(n);
    for(int i=0; i<n; i++)
    {
        scanf("%d %d %d",&temp_n,&temp_a,&temp_b);
        v[i]=make_pair(temp_n,make_pair(temp_a,temp_b));
    }
    sort(v.begin(),v.end());
    
    return 0;
}

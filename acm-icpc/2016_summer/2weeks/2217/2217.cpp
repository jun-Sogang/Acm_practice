#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n;
    int temp;
    int maxVal=0;
    vector <int > v;
    vector <int> ans;
    scanf("%d",&n);
    
    for(int i=0; i<n; i++)
    {
        scanf("%d",&temp);
        v.push_back(temp);
    }
    sort(v.begin(),v.end());
    for(int i=0; i<n; i++)
    {
        ans.push_back(v[i]*(n-i));
    }
    for(int i=0; i<n; i++)
    {
        if(maxVal<ans[i])
            maxVal=ans[i];
    }
    printf("%d\n",maxVal);
    return 0;
}

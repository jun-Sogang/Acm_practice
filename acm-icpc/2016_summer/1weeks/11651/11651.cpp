#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    vector < pair < int, int > > v;
    int n;
    int x,y;
    
    
    scanf("%d",&n);

    for(int i=0; i<n; i++)
    {
        scanf("%d %d",&x, &y);
        v.push_back(make_pair(x,y));

    }
    sort(v.begin(),v.end());

    for(int i=0; i<n; i++)
        printf("%d %d\n",v[i].first,v[i].second);

}

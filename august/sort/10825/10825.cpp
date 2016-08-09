#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

vector < pair < int , pair < int , pair < int, string > > > > s;
int main()
{
    int n;
    char na[12];
    string name;
    int h,e,m;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s %d %d %d",na,&h,&e,&m);
        name=na;
        s.push_back(make_pair(100-h,make_pair(e,make_pair(100-m,name))));
    }
    sort(s.begin(),s.end());
    for(int i=0; i<s.size(); i++)
    {
        printf("%s\n", s[i].second.second.second.c_str());
    }
}

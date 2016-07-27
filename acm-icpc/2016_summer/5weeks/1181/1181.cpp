#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
 
using namespace std;
 
int main()
{
    vector < pair <int, string> > s;
     
    int n;
    char temp[52];
    string v;
 
    scanf("%d",&n);
    s.resize(n);
 
    for(int i=0; i<n; i++)
    {
        cin >> s[i].second;
        s[i].first = s[i].second.length();
    }
 
    sort(s.begin(),s.end());
     
    cout << s[0].second << endl;
    for(int i=1; i<n; i++)
    {
        if(s[i-1].second != s[i].second)
            cout << s[i].second << endl;
    }
}
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
 
using namespace std;
 
int main()
{
    vector < int > v;
 
    int n,m;
    int flag=0;
 
    scanf("%d",&n);
    scanf("%d",&m);
    printf("<");
    for(int i=0; i<n; i++)
        v.push_back(i+1);
    for(int i=0; i<n; i++)
    {
        if(i!=0)
            printf(", ");
        flag=(flag+m-1)%(n-i);
        printf("%d",v[flag]);
        v.erase(v.begin()+flag%n);
    }
    printf(">");
 
    return 0;
}
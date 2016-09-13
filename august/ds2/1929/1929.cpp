#include <stdio.h>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
 
int main(){
    int n;
    int input;
    priority_queue <int, vector<int>, greater<int> > a;
 
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&input);
        if(input==0)
        {
            if(a.empty())
            {
                printf("0\n");
            }
            else
            {
                printf("%d\n",a.top());
                a.pop();
            }
        }
        else
            a.push(input);
    }
 
}
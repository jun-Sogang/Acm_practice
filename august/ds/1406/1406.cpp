#include <cstdio>
#include <stack>
using namespace std;

char s[600001];
char ss[600001];
stack < char > a;
stack < char > b;
int main()
{
    scanf("%s",s);
    for(int i=0; s[i]>='a' && s[i] <= 'z';i++)
    {
        a.push(s[i]);
    }
    int count;
    scanf("%d%*c",&count);
    char temp;
    for(int i=0; i<count; i++){
        //char temp;
        scanf("%c%*c",&temp);
        if(temp=='P')
        {
            scanf("%c%*c",&temp);
            a.push(temp);
        }
        else if(temp == 'L'&& a.size()!=0)
        {
            temp=a.top();
            a.pop();
            b.push(temp);
        }
        else if(temp == 'D' && b.size()!=0)
        {
            temp=b.top();
            b.pop();
            a.push(temp);
        }
        else if(temp == 'B' && a.size()!=0)
        {
            a.pop();
        }
    }
    while(!a.empty())
    {
        b.push(a.top());
        a.pop();
    }
    while(!b.empty())
    {
        printf("%c",b.top());
        b.pop();
    }
    puts("");
    return 0;
}

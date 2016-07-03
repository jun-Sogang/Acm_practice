#include <stack>
#include <cstdio>
#include <string.h>

using namespace std;

int main()
{
    stack < int > s;
    int n;
    char cmd[10];
    int temp;

    scanf("%d",&n);

    while(n--)
    {
        scanf("%s",cmd);

        if(!strcmp(cmd,"push"))
        {
            scanf("%d",&temp);
            s.push(temp);        
        }
        else if(!strcmp(cmd,"pop"))
        {
            if(s.size() != 0)
            {
                printf("%d\n",s.top());
                s.pop();
            }
            else
                printf("-1\n");
        }
        else if(!strcmp(cmd,"top"))
        {
            if(s.size() != 0)
                printf("%d\n",s.top());
            else
                printf("-1\n");
        }
        else if(!strcmp(cmd,"empty"))
        {
            if(s.empty())
                printf("1\n");
            else
                printf("0\n");
        }
        else if(!strcmp(cmd,"size"))
        {
            printf("%lu\n",s.size());
        }
    }
}

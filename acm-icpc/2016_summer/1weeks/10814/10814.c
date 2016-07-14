#include <stdio.h>
#include <string.h>


typedef struct _member{
    int old;
    char name[101];
}member;

int main()
{
    int n;
    
    char s[101];
    member m[100001];
    int year;
    
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d %s",&year,s);
        m[i].old=year;
        strcpy(m[i].name,s);
    }
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(m[i].old<m[j].old)
            {
                year=m[j].old;
                m[j].old=m[i].old;
                m[i].old=year;
                strcpy(s,m[j].name);
                strcpy(m[j].name,m[i].name);
                strcpy(m[i].name,s);
            }
        }
    }
    for(int i=0; i<n; i++)
    {
        printf("%d %s\n",m[i].old,m[i].name);
    }
    return 0;
}

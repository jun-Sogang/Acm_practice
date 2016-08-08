#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int date[12]={31,28,31,30,31,30,31,31,30,31,30,31};
string days[7]={"SUN","MON","TUE","WED","THU","FRI","SAT"};
int main()
{
    int month,day;
    int sum=0;
    scanf("%d %d",&month,&day);
    for(int i=0; i<month-1; i++)
    {
        sum+=date[i];
    }
    sum+=day;
    printf("%s\n",days[sum%7].c_str());
    return 0;
}

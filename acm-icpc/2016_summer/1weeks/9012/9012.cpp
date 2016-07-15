#include <cstdio>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

int main()
{
    int n;
	int len;
	bool flag = true;
	char input[51];

    vector < int > v;
    scanf("%d",&n);
    while(n--)
    {
		flag = true;
		v.clear();
		scanf("%s", input);
		len = strlen(input);
		for (int i = 0; i < len; i++)
		{
			if(input[i]=='(')
				v.push_back(input[i]);
			else
			{
				if (!v.empty())
					v.pop_back();
				else
					flag = false;
			}
		}
		if (!v.empty())
			flag = false;
		if (!flag)
			printf("NO\n");
		else
			printf("YES\n");

    }
    return 0;
}

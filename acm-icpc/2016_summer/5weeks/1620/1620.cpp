#include <cstdio>
#include <algorithm>
#include <map>
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	int n, m;
	string s;
	map < string, int > mon_name;
	map < int, string > mon_num;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
	{
		char temp[21];
		scanf("%s", temp);
		s = string(temp);
		mon_name[s] = i + 1;
		mon_num[i + 1] = s;
	}
	for (int i = 0; i < m; i++)
	{
		char temp[21];
		scanf("%s", temp);
		s = string(temp);
		if (s[0] >= 65 && s[0] <= 90)
		{
			printf("%d\n", mon_name[s]);
		}
		else
		{
			int num = atoi(s.c_str());
			printf("%s\n",mon_num[num].c_str());
		}

	}
	return 0;
}
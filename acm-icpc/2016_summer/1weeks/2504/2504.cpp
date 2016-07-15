#include <cstdio>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;

int main()
{
	vector < char > v;
	vector < char > s;
	int small=0;
	int large=0;
	char temp[31];
	int len;
	int ans = 0;
	int num = 0;
	bool flag = true;
	scanf("%s", temp);
	len = strlen(temp);

	for (int i = 0; i < len; i++)
	{
		v.push_back(temp[i]);
		if (temp[i] == '(')
		{
			s.push_back(temp[i]);
			small++;
		}
		else if (temp[i] == '[')
		{
			s.push_back(temp[i]);
			large++;
		}
		else if (temp[i] == ')')
		{

		}

	}



	return 0;
}
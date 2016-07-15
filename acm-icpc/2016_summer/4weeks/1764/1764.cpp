#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n, m;
	char temp[21];
	vector <string > output;
	string temp_str;
	map < string, int > map;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", temp);
		map[temp] = -1;
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%s", temp);
		if (map[temp] == -1)
		{
			temp_str = temp;
			output.push_back(temp_str);
		}
	}
	sort(output.begin(), output.end());
	int size = output.size();
	printf("%d\n", size);
	for (int i = 0; i < size; i++)
		cout << output[i] << '\n';

	return 0;
}
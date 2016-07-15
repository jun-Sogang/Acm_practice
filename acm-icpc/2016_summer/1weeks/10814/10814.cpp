#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	vector < pair <int, int> > s;
	vector < string > name;
	int n;
	int age;
	char temp[101];
	string v;

	scanf("%d", &n);
	s.resize(n);
	name.resize(n);

	for (int i = 0; i<n; i++)
	{
		scanf("%d", &age);
		scanf("%s",temp);
		v = temp;
		s[i].first = age;
		s[i].second = i;
		name[i] = v;
	}

	sort(s.begin(), s.end());

	for (int i = 0; i < n; i++)
	{
		printf("%d ", s[i].first);
		cout << name[s[i].second] << '\n';
	}
	return 0;
}

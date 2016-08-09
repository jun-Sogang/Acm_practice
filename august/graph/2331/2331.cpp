#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
map < int, int > m;
int next(int a,int p) {
	int sum = 0;
	int temp = 1;
	while (a  % 10 != 0 || a/10 >= 1) {
		for (int i = 0; i < p; i++) {
			temp *= a % 10;
		}
		sum += temp;
		a /= 10;
		temp = 1;
	}
	return sum;
}
int main()
{
	int a, p,i=1,ans;
	
	scanf("%d %d", &a, &p);
	int input = a;
	m[input] = i;
	while (++i)
	{
		input = next(input, p);
		if (m[input] == 0)
			m[input] = i;
		else {
			ans = m[input]-1;
			break;
		}
	}
	printf("%d\n", ans);
	
}
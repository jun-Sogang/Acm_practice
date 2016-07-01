#include <stdio.h>
#include<algorithm>
using namespace std;

struct point{
	int x,y;
	bool operator < (const struct &a) const{
		return x < a.x;
	}
};


bool cmp(const struct point &a, const struct point &b)
{
	return a.x < b.y ;
}

int main()
{
	struct point p[10001];
	int n;
	scanf("%d",&n);

	for(int i=0; i<n ;i++)
		scanf("%d %d\n", &p[i].x, &p[i].y);
	sort(p,p+n);

	for(int i=0; i<n ;i++)
		printf("%d %d\n", p[i].x,p[i].y);

	return 0;
}
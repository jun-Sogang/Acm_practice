#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
int a[1000001];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0; i<m; i++)
		scanf("%d",&a[i]);
	
	sort(a, a + n);

	int start=0,end=a[m],mid=0;
	int ans=0;
	int price=0;
	while(start<end)
	{
		mid=(start+end)/2;
		int egg=0;
		for(int i=1; i<=m; i++)
		{
			if(a[i] >= mid && egg != n)
				egg++;
		}
		if (egg*mid > ans)
		{
			ans = egg*mid;
			price = mid;
			end = mid - 1;
		}
		else
			start = mid + 1;
	
	}
	printf("%d %d",price,ans);

	return 0;
}
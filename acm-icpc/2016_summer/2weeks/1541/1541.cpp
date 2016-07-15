#include <stdio.h>

int main()
{
	char temp;
	bool flag = true;
	int input;
	int ans=0;
	for(;scanf("%d%c", &input, &temp)!=EOF;)
	{
		if (flag)
			ans += input;
		else
			ans -= input;
		if (temp == '-')
			flag = false;
	}
	printf("%d\n", ans);
	return 0;
}
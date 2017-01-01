#include <cstdio>
#include <iostream>
using namespace std;
int main() {
	//84268
	int a[4] = {8,4,2,6};
	int n;
	cin >> n;
	if (n == 0)
		printf("1\n");
	else if (n % 4 == 1)
		cout << "8";
	else if (n % 4 == 2)
		cout << "4";
	else if (n % 4 == 3)
		cout << 2;
	else if (n % 4 == 0)
		cout << "6";
}
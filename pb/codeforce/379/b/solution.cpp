#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
int main() {
	int two, three, five, six;
	int sum = 0;
	int min;
	scanf("%d %d %d %d", &two, &three, &five, &six);
	min=two;
	if(min > five)
		min=five;
	if(min > six)
		min=six;
	sum =min*256;
	min=two-min;
	if(min > three)
		min=three;
	sum+=min*32;
	cout << sum << "\n";
}

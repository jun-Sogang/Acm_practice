#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
int main() {
	int two, three, five, six;
	int sum = 0;
	scanf("%d %d %d %d", &two, &three, &five, &six);
	while (1) {
		if (two > 0 && five > 0 && six > 0) {
			sum += 256;
			two--;
			five--;
			six--;
			continue;
		}
		break;
	}
	while (1) {
		if (two > 0 && three > 0) {
			sum += 32;
			two--;
			three--;
			continue;
		}
		break;
	}
	cout << sum << endl;
}
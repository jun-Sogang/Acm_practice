#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int main() {
	int n;
	int anton = 0;
	int danik = 0;
	string input;
	cin >> n;
	cin >> input;
	for (int i = 0; i < input.length(); ++i) {
		if (input[i] == 'A')
			anton++;
		else if (input[i] == 'D')
			danik++;
	}
	if (anton > danik) {
		printf("Anton\n");
	}
	else if (anton < danik) {
		printf("Danik\n");
	}
	else {
		printf("Friendship\n");
	}


}
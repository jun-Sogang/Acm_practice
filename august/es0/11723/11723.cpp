#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int main() {
	int m;
	int input;
    int n=20;
	unsigned int set = 0;
	char temp1[20];
	string temp;
	scanf("%d", &m);

	while (m--) {
		scanf("%s %d",temp1,&input);
		input--;
		temp = temp1;
		if (temp == "add") {
			set= set | (1 << input);
		}
		else if (temp == "remove") {
			set = set & ~(1 << input);
		}
		else if (temp == "check") {
			if (set & (1 << input))
				puts("1");
			else
				puts("0");
		}
		else if (temp == "toggle") {
			set = set ^ (1 << (input));
		}
		else if (temp == "all") {
			set = (1 << n) - 1;
		}
		else if (temp == "empty") {
			set = 0;
		}

	}
}

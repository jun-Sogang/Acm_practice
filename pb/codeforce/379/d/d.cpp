#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int n;
pair < int, int > black;
vector < int > hori;
vector < int > ver;
vector < int > upper_diag;
vector < int > lower_diag;
bool check() {
	for (int i = 0; i < hori.size(); i++) {
		if (black.second -1== hori[i])
			return false;
	}
	for (int i = 0; i < ver.size(); i++) {
		if (black.first -1== ver[i])
			return false;
	}
	for (int i = 0; i < upper_diag.size(); i++) {
		if(black.first + black.second-2 ==  upper_diag[i])
			return false;
	}
	for (int i = 0; i < lower_diag.size(); i++) {
		if (black.second - black.first == lower_diag[i])
			return false;
	}
	return true;
}
int main() {
	char temp;
	cin >>n;
	scanf("%d %d", &black.first, &black.second);
	scanf("%c", &temp);
	for (int i = 0; i < n; i++) {
		char a;
		int b, c;
		scanf("%c", &a);
		scanf("%c", &temp);
		scanf("%d %d", &b, &c);
		scanf("%c", &temp);

		if (a == 'R') {
			hori.push_back(c-1);
			ver.push_back(b-1);
		}
		else if (a == 'B') {
			upper_diag.push_back(b + c-2);
			lower_diag.push_back(c - b);
		}
		else {
			upper_diag.push_back(b + c-2);
			lower_diag.push_back(c - b);
			hori.push_back(c-1);
			ver.push_back(b-1);
		}
	}
	if (!check()) {
		printf("YES\n");
	}
	else {
		printf("NO\n");
	}
}
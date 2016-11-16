#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
int main() {
	int n, m, k;
	int one_portion_takes;
	int full_manapoints;
	vector < int > first_type_seconds;
	vector < int > first_type_mana;
	vector < int > second_type_seconds;
	vector < int > second_type_mana;

	cin >> n >> m >> k;
	cin >> one_portion_takes >> full_manapoints;
	for (int i = 0; i < m; i++) {
		int temp;
		scanf("%d", &temp);
		first_type_seconds.push_back(temp);
	}
	for (int i = 0; i < m; i++) {
		int temp;
		scanf("%d", &temp);
		first_type_mana.push_back(temp);
	}
	for (int i = 0; i < k; i++) {
		int temp;
		scanf("%d", &temp);
		second_type_seconds.push_back(temp);
	}
	for (int i = 0; i < k; i++) {
		int temp;
		scanf("%d", &temp);
		second_type_mana.push_back(temp);
	}
	vector < int > ratio_first;
	double maximum = 0;
	int max_i;
	for (int i = 0; i < k; i++) {
		double temp;
		temp = second_type_mana[i] / second_type_seconds[i];
		if (i == 0) {
			maximum = temp;
			max_i = 0;
		}
		if (second_type_mana[i] < full_manapoints && i != 0) {
			if (maximum < temp) {
				maximum = temp;
				max_i = i;
			}
		}
	}
	full_manapoints -= second_type_mana[max_i];
	cout << min << "\n";
}
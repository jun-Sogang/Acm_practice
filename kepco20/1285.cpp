#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;


int n;
bool coin[22][22];
bool board[22][22];

/*
3
HHT
THH
THT
*/
long long go() {
    long long result = 9999999999999999;

    for (int i = 0; i < (1 << n); ++i) {
        long long candidate = 0;
        for (int j = 0; j < n; ++j) {
            int sum = 0;
            for (int k = 0; k < n; ++k) {
                bool now = coin[j][k];

                if ((1 << k) & i) {
                    now = !now;
                } 
                sum += now;
            }
            candidate += min(sum, n - sum);
        }
        result = min(candidate, result);
    }
    return result;
}

int main() {

    cin >> n;
    char input;

    for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			while (true)
			{
				scanf("%1c", &input);
				if (input != '\n') break;
			}
            if (input == 'T') {
                coin[i][j] = true;
            }
            else {
                coin[i][j] = false;
            }
		}
	}

    cout << go() << endl;
    
    return 0;
}
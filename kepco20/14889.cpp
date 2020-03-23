#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int map[22][22];
int n;
vector <int> ind;

int go() {
    int result = 999999999;

    for (int i = 0; i < n / 2; ++i){
        ind.push_back(1);
        ind.push_back(0);
    }
    
    sort(ind.begin(), ind.end());

   
    do{
        int a = 0;
        int b = 0;

		for(int i = 1; i < n; ++i){
            

            for (int j = 0; j < i; ++j) {
                if (ind[i] == 1 && ind[j] == 1) {
				    a += map[i][j] + map[j][i];
			    }
                else if (ind[i] == 0 && ind[j] == 0) {
                    b += map[i][j] + map[j][i];
                }
            }
		}
        
		result = min(result, abs(a - b));

	}while(next_permutation(ind.begin(), ind.end()));

    return result;
}


int main() {

    cin >> n;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> map[i][j];
        }
    }

    cout << go() << endl;

    return 0;
}
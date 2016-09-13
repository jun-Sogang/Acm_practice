#include <cstdio>
#include <algorithm>
#include <math.h>
using namespace std;
double x, y, c;
bool check(double mid) {
	double d = mid;
	double check_c = (sqrt(x*x - d*d)*sqrt(y*y - d*d)) / (sqrt(x*x - d*d) + sqrt(y*y - d*d));
	if (check_c > c)
		return true;
	return false;
}
int main(){
	
  
	while (scanf("%lf %lf %lf", &x, &y, &c) == 3) {
		int cnt = 10000;
		double left, right, mid;
		left = 0;
		right = min(x, y);
		while (cnt--) {
			mid = left + (right - left) / 2;
			if (check(mid)) {
				left = mid;
			}
			else
				right = mid;
		}
		printf("%.3lf\n", mid);
    }
}

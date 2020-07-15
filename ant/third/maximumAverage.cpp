// 重さ:価値がwi, viのn個の品物がある。
//この中からちょうどk個選んだ時の重さあたりの価値の最大値
#include<iostream>
using namespace std;
int n, k;
int main() {
	cin >> n >> k;
    int x[n][2];
    for (int i = 0; i < n; i++) {
		cin >> x[i][0] >> x[i][1];
	}
}

bool C(double y, int x[][]) {
	int z[];
	for (int i = 0; i < n; i++) {
        z[i] = x[i][1] - y * x[i][0];
    }
	sort(z, z + n);
	int sum;
	for (int i = 0; i < k; i++) {
		sum += z[i];
	}
	return sum >= 0;
}

double solve(int x[][]) {
	double min, max, mid;
	min =  0;
	max = 10;
	for (int i = 0; i < 10; i++) {
		mid = (min + max) / 2;
		if (C[mid, x]) {
			min = mid;
		} else {
			max = mid;
		}
	}
	return mid;
}

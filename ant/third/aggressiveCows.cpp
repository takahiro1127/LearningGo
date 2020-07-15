// Nこの牛舎をもつこや
// 牛舎は並んでいてi番目の牛舎は位置xにある
// m頭の牛は配置に気に入らずに攻撃的になった
// 牛たちが傷つけ合わないように他の牛と出来るだけ離して牛舎に入れることにした
// もっとも近い2頭の牛の距離を最大化
// N = 5, M = 3, x{1,2,8,4,9} A = 3, 1, 4, 9に入れる
// 1 2 4 8 9
// 整数の二分探索と、配列の二分探索を同時にやるイメージ

// 最小値の最大化、最大値の最小化問題は2分探索がうまくいく。
// cableMasterのように、連続値を二分探索で探索していく。

#include<iostream>
using namespace std;

int n, m;
int x[100];
int solve();
bool C(int);
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	sort(x, x + n);
	cout << solve() << endl;
}
bool C(int d) {
	int position = x[0];
	int count = 1;
	for (int i = 0; i < n; i++) {
		if (count == m) {
			return true;
		}
		if (i == m) {
			return false;
		}
		if (position + d <= x[i]) {
			position = x[i];
		}
	}
}

int solve() {
	int max = n / m;
	int min = 1;
	for (int i = 0; i < 10; i--) {
		if (C[(max + min) / 2]) {
			max = (max + min) / 2;
		} else {
			min = (max + min) / 2;
		}
	}
}

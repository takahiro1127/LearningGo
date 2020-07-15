// nこの互いに区別できない商品をm個以下に分割する方法の総数を求め、Mで割ったあまり
// n = 4, m = 3, M = 1あ000
// 4(1 + 1 + 2, 1 + 3, 2 + 2, 4)
#include<iostream>
using namespace std;
int solve(int, int);
int A[100][100];
int main() {
  int n, m, M;
  cin >> n >> m >> M;
  cout << solve(n, m) % M << endl;
}

int solve(int n, int m) {
  // solve(n - 1, m - 1), solve(n - 2, m - 2)... forで回す
  if (A[n][m]) {
    return A[n][m];
  }
  if (n == m || m == 1) {
    return 1;
  }
  int count = 0;
  for (int i = 0; i < n - m + 1; i++) {
    count += solve(n - i, m - 1);
  }
  A[n][m] = count;
  return count;
}
//m個以下に分割するので違う上に、これだと1,2,1と1,1,2が分けれていないのでだめ
//nをm個いかに分割する方法数をd[n][m]とすると
//d[n][m] = d[n - m][m] + d[n][m - 1];
//d[n - m][m]はnをm個に分割していて、かく分割をaiとした時にai - 1(ai - 1 > 0が任意のiについて成り立つならば)がnのm分割となる
//d[n][m - 1]はnをm - 1個以下に分割することができる
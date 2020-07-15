// 個数付き部分和問題
#include<iostream>
using namespace std;
int solve(int p[][2], int i, int k, int n);
int mem[][];
int main() {
  int n, k;
  cin >> n;
  int p[n][2];
  for (int i = 0; i < n; i++) {
    cin >> p[i][0] >> p[i][1];
  }
  cin >> k;
  for (int i = 0; i < n; i++) {
    for (int j = n - 1; j > i; j--) {
      if (p[j][0] > p[j - 1][0]) {
        swap(p[j][0], p[j - 1][0]);
      }
    }
  }
  solve(p, 0, k, n);
}

int solve(int p[][2], int i, int k, int n) {
  bool cansolve;
  if (p[i][0] > k) {
    mem[][] = solve(p, i + 1, k, n);
  } else if (p[i][0] == k) {
    cout << "true" << endl;
    return true;
  } else {
    // p[i][0]をp[i][1]個使った未来に分岐させたい。
    // iばんめより先の数字を使って、k - p[i][0]を再現できるかどうか
  }
}

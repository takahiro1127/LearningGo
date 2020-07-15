#include<iostream>
using namespace std;
int l[100];
int search(int[], int);
int main() {
  int n, max;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    l[i] = 1;
  }
  search(a, n - 1);
  cout << l[n - 1] << endl;
}

int search(int a[], int i) {
  if (i == 0) {
    return 1;
  }
  if (l[i] > 1) {
    return l[i];
  }
  for (int j = i; j >= 0; j--) {
    for (int k = j - 1; k >= 0; k--) {
      if (a[j] > a[k]) {
        //後ろから配列をみていく、基準なる値としてjを保持する
        //jを一番最後の要素としてもつlicを考える
        //jより前の要素をみていき、jよりも小さい場合、そのkが一番後ろに来るlisの値+1が自分の値となる
        l[j] = max(search(a, k) + 1, l[j]);
      }
    }
  }
  return l[i];
}

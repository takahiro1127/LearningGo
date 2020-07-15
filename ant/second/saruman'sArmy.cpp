#include<iostream>
using namespace std;

int main() {
  int n, r;
  cin >> n >> r;
  int x[n];
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  //バブルソート
  for (int j = 1; j < n; j++) {
    for (int i = n - j; i >= 0; i--) {
      if (x[i] < x[i - 1]) {
        swap(x[i], x[i - 1]);
      }
    }
  }
  int s, count;
  s = 0;
  count = 1;
  for (int i = 0; i < n; i++) {
    if (x[s] + 2 * r < x[i]) {
      s = i;
      count++;
    }
  }
  cout << count << endl;
}

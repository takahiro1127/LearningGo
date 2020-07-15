#include<iostream>
using namespace std;

int main() {
  string s;
  cin >> s;
  int n;
  n = s.size();
  int k, m;
  k = 0;
  m = 0;
  for (int i = 0; i < n; i++) {
    if (i == n - 1) {
      if (m == 0) {
        k++;
      } else {
        if (m % 3 == 2) {
          k += 2 * (m / 3);
        } else {
          k += 2 * (m / 3) + 1;
        }
      }
      continue;
    }
    if (s[i] != s[i + 1]) {
      if (m == 0) {
        k++;
      } else {
        if (m % 3 == 2) {
          k += 2 * (m / 3);
        } else {
          k += 2 * (m / 3) + 1;
        }
        m = 0;
      }
    } else {
      m++;
    }
  }
  cout << k << endl;
  return 0;
}

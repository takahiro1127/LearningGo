#include <iostream>
using namespace std;

int main() {
  int n, r;
  int A[n][n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      A[j][j] = 100000;
    }
  }
  for (int i = 0; i < r; i++) {
    int k, l;
    cin >> k >> l >> A[k - 1][l - 1];
  }

  
}

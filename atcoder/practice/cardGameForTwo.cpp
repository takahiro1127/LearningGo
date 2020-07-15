#include<iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int X[n];
  int A[2];
  A[0] = 0;
  A[1] = 0;
  for (int i = 0; i < n; i++) {
    cin >> X[i];
  }

  for (int i = 0; i < n; i++) {
    for (int j = n - 1; j > i; j--) {
      if (X[j] > X[j - 1]) {
        swap(X[j], X[j - 1]);
      }
    }
    A[i%2] += X[i];
  }
  cout << (A[0] - A[1]) << endl;
  return 0;
}

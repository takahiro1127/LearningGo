#include<iostream>
using namespace std;

void coinUseCount(int, int[], int[]);

int k[6] = {1, 5, 10, 50, 100, 500};
int main() {
  int c[6];
  int d[6];
  int A;
  for (int i = 0; i < 6; i++) {
    cin >> c[i];
    d[i] = 0;
  }
  cin >> A;
  coinUseCount(A, c, d);
}

void coinUseCount(int A, int c[], int d[]) {
  if (A == 0) {
    for (int i = 5; i >= 0; i--) {
      cout << d [i] << endl;
    }
  }
  for (int i = 5; i >= 0; i--) {
    if (k[i] < A && c[i] > 0) {
      c[i] -= 1;
      d[i] += 1;
      coinUseCount(A - k[i], c, d);
    }
  }
}

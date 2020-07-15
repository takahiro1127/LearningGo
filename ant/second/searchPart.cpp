#include <iostream>
using namespace std;

int main() {
  int n, k;
  int a[n];

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cin >> k;
  cout << partSum(a, 0, k) << endl;
  return 0;
}

bool partSum(int a[], int i, int k) {
  if (k - a[i] < 0) {
    return partSum(a, i + 1, k);
  } else if (k - a[i] == 0) {
    return true;
  }
  return partSum(a, i + 1, k) || partSum(a, i + 1, k - a[i]);
}

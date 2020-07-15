#include<iostream>
using namespace std;


int main() {
  int l, n;
  cin >> l >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int minT = 0;
  int maxT = 0;

  for (int i = 0; i < n; i++) {
    minT = max(minT, min(a[i], l - a[i]));
    maxT = max(maxT, max(a[i], l - a[i]));
  }
  cout << minT << maxT << endl;
}

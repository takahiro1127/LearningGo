#include <iostream>
using namespace std;

int main()
{
  int n, k, q, max;
  max = 0;
  cin >> n >> k >> q;
  int t[n];
  for (int i = 0; i < n; i++) {
    t[i] = 0;
  }
  for (int i = 0; i < q; i++) {
    int m;
    cin >> m;
    t[m - 1] += 1;
  }
  for (int i = 0; i < n; i++) {
    if (k + t[i] - q> 0) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
}

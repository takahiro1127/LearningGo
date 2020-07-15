#include<iostream>
using namespace std;

int main() {
  int n, count;
  count = 0;
  cin >> n;
  bool D[100];
  for (int i = 0; i < n; i++) {
    int m;
    cin >> m;
    if (!D[m - 1]) {
      D[m - 1] = true;
      count += 1;
    }
  }
  cout << count << endl;
  return 0;
}

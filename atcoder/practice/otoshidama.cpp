#include<iostream>
using namespace std;

int main() {
  int n, y;
  cin >> n >> y;
  int combination[3];
  bool searching = true;
  for (int i = 0; i <= n && searching; i++)
  {
    for (int j = 0; j <= n - i && searching; j++)
    {
      int k = n - i - j;
      if (10000 * i + 5000 * j + 1000 * k == y) {
        combination[0] = i;
        combination[1] = j;
        combination[2] = k;
        searching = false;
      }
    }
  }
  if (searching) {
    cout << "-1 -1 -1" << endl;
  } else {
    cout << combination[0] << " " << combination[1] << " " << combination[2] << endl;
  }
  return 0;
}

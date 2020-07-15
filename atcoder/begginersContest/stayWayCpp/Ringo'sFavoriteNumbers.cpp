#include<iostream>
using namespace std;

int main() {
  int d, n;
  cin >> d >> n;
  if (n == 100)n++;
  if (d == 0) {
      cout << n << endl;
  }
  if (d == 1) {
      cout << 100 * n << endl;
  }
  if (d == 2) {
      cout << 10000 * n << endl;
  }
}

#include<iostream>
using namespace std;

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  int someSum = 0;
  for (int i = 0; i <= n; i++) {
    int p, q, r, x, y, z;
    p = i/10000;
    q = i/1000 - p * 10;
    r = i/100 - p * 100 - q * 10;
    x = i / 10 - p * 1000 - q * 100 - r * 10;
    y = i - p * 10000 - q * 1000 - r * 100 - x * 10;
    z = p + q + r + x + y;
    if (z >= a && z <= b) {
      someSum += i;
    }
  }
  cout << someSum << endl;
}

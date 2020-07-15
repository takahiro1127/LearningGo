#include<iostream>
using namespace std;

int count(int a, int b, int c, int x);

int main()
{
  int a, b, c, x;
  cin >> a;
  cin >> b;
  cin >> c;
  cin >> x;
  cout << count(a, b, c, x);
  return 0;
}

// メモ化
int count(int a, int b, int c, int x) {
  int cCount = 0;
  for (int i = 0; i <= a; i++) {
    for (int j = 0; j <= b; j++) {
      for (int k = 0; k <= c; k++) {
        if ((x - i * 500 - j * 100 - k * 50) == 0) {
          cCount += 1;
          break;
        }
      }
    }
  }
  return cCount;
}

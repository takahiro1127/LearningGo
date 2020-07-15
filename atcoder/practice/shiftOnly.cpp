#include<iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int counter = 30;
  for (int i = 0; i < n; i++) {
    int m;
    cin >> m;
    for (int j = 1; j <= counter; j++) {
      if (m % 2 == 0) {
        m /= 2;
        continue;
      } else {
        counter = j - 1;
        break;
      }
    }
  }
  cout << counter << endl;
  return 0;
}

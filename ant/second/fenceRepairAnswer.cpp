#include<iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int l[n];
  for (int i = 0; i < n; i++) {
    cin >> l[i];
  }

  for (int j = 1; j < n; j++) {
    for (int i = n - j; i >= 0; i--) {
      if (l[i] < l[i - 1]) {
        swap(l[i], l[i - 1]);
      }
    }
  }

  for 
}

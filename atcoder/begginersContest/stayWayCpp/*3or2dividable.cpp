#include<iostream>
using namespace std;

int count2Dividable(int);

int main() {
  int n, count;
  count = 0;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    count += count2Dividable(a[i]);
  }
  cout << count << endl;
  return 0;
}

int count2Dividable(int n) {
  int count;
  count = 0;
  if(n%2 == 0) {
    count = count2Dividable(n/2) + 1;
  }
  return count;
}

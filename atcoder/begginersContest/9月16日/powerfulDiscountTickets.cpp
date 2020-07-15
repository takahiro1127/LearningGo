#include <iostream>
using namespace std;

int find(int);

int main()
{
  int n, m;
  cin >> n >> m;
  int A[n][2];
  for (int i = 0; i < n; i++) {
    A[i][0] = 0;
    cin >> A[i][0];
    A[i][1] = 0;
  }
  for (int j = 0; j < m; j++) {
    for (int i = n - 1; i >= 0; i--) {
      if (A[i][0] > A[i - 1][0])
      {
        swap(A[i][0], A[i - 1][0]);
      }
    }
    A[0][1] += 1;
  }
  int sum = 0;
  for (int i = 0; i < n; i++) {
    int mother;
    mother = find(A[i][1]);
    sum += A[i][0]/mother;
  }
  cout << sum << endl;
  return 0;
}

int find(int n) {
  int m = 1;
  for (int i = 0; i < n; i++) {
    m = m * 2;
  }
  return m;
}

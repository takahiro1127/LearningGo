#include<iostream>
#include <cstdlib>
using namespace std;

/*全探索アプローチ*/

int allCombination(int[], int, int, int[][3], int);
int calcValue(int[], int[][3], int);

int main() {
  int n, m, value;
  cin >> n >> m;
  int a[n][3];
  int j[n];
  for (int i = 0; i < n; i++) {
    j[i] = 0;
    cin >> a[i][0] >> a[i][1] >> a[i][2];
  }
  value = allCombination(j, 0, m, a, n);
  cout << value << endl;
  return 0;
}

int allCombination(int j[], int i, int m, int a[][3], int n){
  int value;
  if (i < m) {
    int k, l;
    k = allCombination(j, i, m, a, n);
    j[i] = 1;
    l = allCombination(j, i+1, m, a, n);
    return max(k, l);
  } else if (i == m) {
    return calcValue(j, a, n);
  } else {
    return 0;
  }
}

int calcValue(int j[], int a[][3], int n) {
  int values[3];
  values[0] = 0;
  values[1] = 0;
  values[2] = 0;
  int m;
  m = sizeof(j)/sizeof(int);
  for (int i = 0; i < m; i++) {
    if (j[i] == 1) {
      values[0] += a[i][0];
      values[1] += a[i][1];
      values[2] += a[i][2];
    }
  }
  return abs(values[0]) + abs(values[1]) + abs(values[2]);
}

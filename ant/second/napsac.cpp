#include<iostream>
using namespace std;

int combinationSearch(int[], int, int, int, int, int);

int main() {
  int n, limW;
  cin >> n >> limW;
  int A[n][2];
  for (int i = 0; i < n; i++) {
    cin >> A[i][0] >> A[i][1];
  }
  cout << combinationSearch(A, limW, n, 0, 0, 0) << endl;
}

int combinationSearch(int A[][2], int limW, int n, int i, int totalValue, int totalWeight) {
  if (i == n - 1) {
    return totalWeight;
  }
  if (limW > totalWeight + A[i][0]) {
    return max(combinationSearch(A, limW, i + 1, n, totalValue + A[i][1], totalWeight + A[i][0]), combinationSearch(A, limW, i + 1, n, totalValue, totalWeight));
  } else {
    return combinationSearch(A, limW, i + 1, n, totalValue, totalWeight);
  }
}

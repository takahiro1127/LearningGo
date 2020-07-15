#include<queue>
#include<iostream>
using namespace std;
int main() {
  priority_queue<int> pque;
  int N, L, P;
  cin >> N >> L >> P;
  int A[N], B[N];
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  for (int i = 0; i < N; i++) {
    cin >> B[i];
  }
  int p = 0;
  int count = 0;
  for (int j = 0; P < L; j++) {
    for (int i = p; i < N; i++) {
      if (A[i] <= P) {
        pque.push(B[i]);
        p = i + 1;
      }
    }
    if (P < L) {
      P += pque.top();
      pque.pop();
      count++;
    } else {
      cout << count << endl;
    }
  }
  cout << -1 << endl;
}
// まず、N進む。N以下のA[i]を燃料の量を基準でpriority_queueに入れる。
// N+A[i]進み、N+A[i]以下のA[i]を燃料の量を基準でpriority queueに入れる。

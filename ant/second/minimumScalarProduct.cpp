#include <iostream>
#include <queue>
using namespace std;
int main() {
  priority_queue<int> xque, yque;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int m;
    cin >> m;
    xque.push(m);
  }

  for (int i = 0; i < n; i++) {
    int m;
    cin >> m;
    yque.push(m);
  }

  // 簡単なので以下略
}

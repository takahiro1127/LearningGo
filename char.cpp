#include <iostream>
#include <vector>
#include <numeric>
// https://atcoder.jp/contests/apg4b/tasks/APG4b_ad?lang=ja
// 文字コードの扱い方
// 文字コードの足し算引き算
// 文字列の足し算引き算
#define all(v) v.begin(), v.end()
using namespace std;
 
int main() {
  for (int i = 0; i <= ('Z' - 'A'); i++) {
    cout << (char)('A' + i);
  }
  cout << (char)('x' + ('A' - 'a')) << endl; // 'X' 小文字→大文字
  cout << (char)('X' - ('A' - 'a')) << endl; // 'x' 大文字→小文字)
}
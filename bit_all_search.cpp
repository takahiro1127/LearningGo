#include <iostream>
using namespace std;
#define MAXN 5
int main() {
  // 3ビットのビット列をすべて列挙する
  //定数である必要がある。
  for (int tmp = 0; tmp < (1 << MAXN); tmp++) {
    bitset<MAXN> s(tmp);
    x = 2;
    // 2ばんめの要素を1にする
    s.set(x);
    // 2ばんめの要素を1にする
    s.reset(x);
    // i番目の値を出力 1か0
    cout << s[i] << end;
    // ビット列を出力
    // 列挙に i が含まれるか
    // if (bit & (1<<i)) {
    cout << s << endl;
  }
}
bool C(vector<bool> bit) {
    //判定式
    return bit[0] == 1;
}
bool search(vector<bool> bit, int n) {
    if (n == N) {
        return C(bit);
    }
    first_ans = search(bit, n + 1);
    bit[n] = true;
    second_ans = search(bit, n + 1);
    return first_ans || second_ans;
}

bool bitSearch(int n) {
    vector<bool> bit;
    rep(i, n) bit.push_back(false);
    return search(bit, 0);
}
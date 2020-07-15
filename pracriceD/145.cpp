#include<iostream>
using namespace std;
int x, y;
int n(int, int);
long long comb(int, int);
int main() {
    cin >> x >> y;
    int n;
    n = n(x, y);
    //ここで端点は(2n, n)または(n, 2n)なので、引き算で簡単に端点からm番目の点であることがわかる
    if (x < y) {
        m = x - n;
    } else {
        m = y - n;
    }
    cout << comb(n, n - m - 1)[n][n - m - 1] << endl;
    //ロジック正解
}
//回答ロジックでは、座標の合計が3の倍数であることでチェックをし、
//(1, 2)移動の回数をn回、(2, 1)移動の回数をm回として、n+mCmを求めていた。

//自分の回答の場合、チェックのところはよくて、そこから移動の総回数(n = n + m)としていた。
//また端点から何番目であるかということを気にすることは何回(1, 2)をしたかということと同義であるため、正解出力は正しい
//ただ解答のロジックの方が明快単純である。

int n(int x, int y) {
    if ((x + y) % 3 != 0) {
        return 0;//規則性に沿った線上にないものは0
    }
    return (x + y) / 3;
}

std::vector<std::vector<long long>> comb(int n, int r) {
    std::vector<std::vector<long long>> v(n + 1,std::vector<long long>(n + 1, 0));
    for (int i = 0; i < v.size(); i++) {
    v[i][0] = 1;
    v[i][i] = 1;
    }
    for (int j = 1; j < v.size(); j++) {
        for (int k = 1; k < j; k++) {
            v[j][k] = (v[j - 1][k - 1] + v[j - 1][k]);
        }
    }
    return v;
}
//って思ったけど、図を書いてみると→規則性ありなんだなー
//0, 0 -> (1, 2) (2, 1) -> (2, 4) (3, 3) (4, 2) -> (3, 6) (4, 5) (5, 4) (6, 3) -> (4, 8)
// 1        2                   3                           4
//これで簡単に判別できる
//判別の方法は
//y = -x + 3n上にあるので、
//まず、これから、nを求める
//n上の点は(x+1) ^ n+1の係数通り行く方法がある
//端点は(2n, n)または(n, 2n) これは1,2のみを選び続けた点であるから
//端からmばんめであることを求める→これはひ
//nC(n - (m - 1))で求めることができる
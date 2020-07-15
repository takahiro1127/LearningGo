// 問題設定
// n種類の品物i番目はaiこある、同じ種類の品物は区別できない
// これらからmこ選ぶ組み合わせの総数をMでったもの
// n 3
// m 3
// a = 1 2 3
// M = 10000
// 6
// 漸化式
// n種類の中からm個選ぶ組み合わせ = n - 1種類の中からm個選ぶ組み合わせ　* n /m

// A[i + 1][j] = i番目までの商品からj個選ぶ組み合わせの総数

    // #include<iostream>
    // using namespace std;

    // int main() {
    //   int n, m;
    //   cin >> n >> m;
    //   int a[n];
    //   for (int i = 0; i < n; i++) {
    //     cin >> a[i];
    //   }
    //   int A[n][m];
    //   for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //       if (j == 0 && i == 0) {
    //         A[i][j] = 1;
    //       } else if (j == 0) {
    //         A[i][j] = 1;
    //       } else if (i == 0) {
    //         A[i][j] = 0;
    //       }
    //     }
    //   }
    // }

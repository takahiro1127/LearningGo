#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <list>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
// アドレス、メモリ、参照などまとめ
int main()
{
    int n = 100;
    // アドレスが出力される
    cout << &n << endl;
    // ポインタ変数を宣言
    int* m = &n;
    // ポインタ変数を参照するので、アドレスが出力される
    cout << m << endl;
    // ポインタ変数の値を出力する。
    cout << *m << endl;

    n = 200;
    // 参照元の値を変更すると、ポインタ変数の値の出力も変化する。
    cout << *m << endl;

    *m = 300;
    // ポインタ変数の刺す場所の値を変更すると、元の変数も修正される。
    cout << n << endl;
}
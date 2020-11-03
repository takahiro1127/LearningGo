#include <iostream>
#include <algorithm>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
#define MAX_N 100000
// string perm[MAX_N];
int perm[MAX_N];
// bool perm[MAX_N];

int main()
{
    int n;
    cin >> n;
    rep(i, n) perm[i] = i;
    // 文字列の場合↓
    // rep(i, n) cin >> perm[i];
    // n! n階乗の組み合わせを順番に出力
    // n個の並び替えで考えられる順番を全て列挙
    // 出てくる順番は辞書順
    rep(i, n) cout << perm[i] << " ";
    cout << endl;
    do {
        rep(i, n) cout << perm[i] << " ";
        cout << endl;
    } while (next_permutation(perm, perm + n));
}
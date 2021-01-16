#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map> // ヘッダファイルインクルード
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
// ロジックはあっている。
ll mod = 1000000007;
int main() {
    ll n;
    cin >> n;
    vector<ll> A(n);
    rep(i, n) cin >> A[i];
    //自分より前の人の最大値を記録する。
    vector<ll> MAX(n);
    MAX[0] = 0;
    for (int i = 1; i < n; i++) {
        MAX[i] = max(A[i - 1], MAX[i - 1]);
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] < MAX[i]) {
            ans += MAX[i] - A[i];
        }
    }
    cout << ans << endl;
}
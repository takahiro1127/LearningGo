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
    //累積和をとるのが良さそう
    vector<ll> S(n);
    S[0] = 0;
    for (int i = 1; i < n; i++) {
        S[i] = A[i - 1] + S[i - 1];
    }
    ll ans = 0;
    rep(i, n) ans += A[i] * S[i];
    cout << ans % mod << endl;
}
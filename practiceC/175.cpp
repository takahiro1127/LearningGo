#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map> // ヘッダファイルインクルード
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
int main() {
    ll x, k, d;
    cin >> x >> d >> k;
    x = abs(x);
    ll ans;
    if (x >= k) {
        ll xmodk = x / k;
        if (xmodk <= d) {
            x = x % k;
            d -= xmodk;
        } else {
            x -= k * d;
            d = 0;
        }
    }
    if (d % 2 == 0) {
        ans = abs(x);
    } else {
        ans = abs(x - k);
    }
    cout << ans << endl;
}
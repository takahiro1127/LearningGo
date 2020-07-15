#include<iostream>
#include<vector>
#include <cstdint>
#include <math.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
ll m, p, q;
const int MAX = 1000000000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];
// 考え方は合ってるけど、高速化ができていない

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
    cin >> m >> p >> q;
    if (m == 0) {
        cout << 0 << endl;
    }
    COMinit();
    ll al = COM(m, p);
    ll bl = COM(m, q);
    ll c = (pow(2, m) - 1);
    ll ans = c % MOD - al - bl;
    cout << ans << endl;
}
// uintmax_t combination(unsigned int n, unsigned int r) {
//   if ( r * 2 > n ) r = n - r;
//   uintmax_t dividend = 1;
//   uintmax_t divisor  = 1;
//   for ( unsigned int i = 1; i <= r; ++i ) {
//     dividend *= (n-i+1);
//     divisor  *= i;
//   }
//   return dividend / divisor;
// }

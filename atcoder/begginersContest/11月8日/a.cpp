#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)
ll a[100];
ll k;
std::vector<bool> IsPrime;

void sieve(size_t max){
    if(max+1 > IsPrime.size()){     // resizeで要素数が減らないように
        IsPrime.resize(max+1,true); // IsPrimeに必要な要素数を確保
    };
    IsPrime[0] = false; // 0は素数ではない
    IsPrime[1] = false; // 1は素数ではない

    for(size_t i=2; i*i<=max; ++i) // 0からsqrt(max)まで調べる
        if(IsPrime[i]) // iが素数ならば
            for(size_t j=2; i*j<=max; ++j) // (max以下の)iの倍数は
                IsPrime[i*j] = false;      // 素数ではない
}

ll getGcd(ll j) {
    ll count = 0;
    for (int i = 0; i < k; i++) {
        if (a[i] % j == 0) {
            count++;
        }
    }
    return count;
}


int main()
{
    cin >> k;
    rep(i, k) cin >> a[i];
    sieve(10001);
    ll max_gcd_number = 2;
    ll max_gcd = 0;
    for (int i = 2; i < 1001; i++) {
        if (IsPrime[i]) {
            ll gcd = getGcd(i);
            if (max_gcd < gcd) {
                max_gcd = gcd;
                max_gcd_number = i;
            }
        }
    }
    cout << max_gcd_number << endl;
}
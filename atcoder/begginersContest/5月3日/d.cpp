#include<iostream>
#include<vector>
#include <queue>
#include <string>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
ll powf(ll k) {
    return k * k * k * k * k;
}
int main() {
    ll x;
    cin >> x;
    int a, b;
    for (ll i = 0; i <= 200; i++) {
        ll five = powf(i);
        for (ll j = -75; j <= 200; j++) {
            ll fiveb = powf(j);
            if (five - fiveb == x) {
                a = i;
                b = j;
                goto LAST;
            }
        }
    }
LAST:
    cout << a << " " << b << endl;
}

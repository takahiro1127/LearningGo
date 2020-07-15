#include<iostream>
#include <algorithm> // sort
#include <map> // pair
using namespace std;
typedef unsigned long long ll;
#define rep(i, n) for(ll i = 0; i < (n); i++)
int main() {
    ll n, k, a, count;
    ll kount[100001], b[100001], c[100001];
    bool is[100001];
    count = 0;
    cin >> n;
    for (ll i = 0; i < n; i++) {
        cin >> a;
        if (!is[a]) {
            kount[a] = 1;
            is[a] = true;
        } else {
            kount[a]++;
        }
        count += a;
    }
    cin >> k;
    rep(i, k) cin >> b[i] >> c[i];
    for (ll i = 0; i < k; i++) {
        count += (c[i] - b[i]) * kount[b[i]];
        if (is[c[i]]) {
            kount[c[i]] += kount[b[i]];
        } else {
            is[c[i]] = true;
            kount[c[i]] = kount[b[i]];
        }
        kount[b[i]] = 0;
        cout << count << endl;
    }
}

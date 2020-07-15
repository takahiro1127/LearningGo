#include<iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)

int main() {
    ll n, k;
    ll p[1000];
    cin >> n >> k;
    rep(i, n) cin >> p[i];
    sort(p, p + n);
    ll count = 0;
    rep(i, k) count += p[i];
    cout << count << endl;
}

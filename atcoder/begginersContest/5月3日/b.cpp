#include<iostream>
#include<vector>
#include <algorithm>
#include <map> // pair
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
int main() {
    ll n, k;
    cin >> n >> k;
    ll a[n];
    rep(i, n) a[i] = 0;
    for (int i = 0; i < k; i++) {
        ll d;
        cin >> d;
        for (int j = 0; j < d; j++) {
            ll b;
            cin >> b;
            a[b - 1] = 1;
        }
    }
    ll count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            count++;
        }
    }
    cout << count << endl;
}

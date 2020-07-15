#include<iostream>
#include<vector>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
ll h[100000];
ll a, b;
bool good[100000];
ll n, m;

int main() {
    cin >> n >> m;
    for (ll i = 0; i < n; i++) {
        cin >> h[i];
        good[i] = true;
    }
    for (ll i = 0; i < m; i++) {
        cin >> a >> b;
        if (h[a - 1] > h[b - 1]) {
            good[b - 1] = false;
        } else if (h[a - 1] < h[b - 1]) {
            good[a - 1] = false;
        } else {
            good[a - 1] = false;
            good[b - 1] = false;
        }
    }
    ll count = 0;
    for (ll i = 0; i < n; i++) {
        if (good[i]) {
            count++;
        }
    }
    cout << count << endl;
}

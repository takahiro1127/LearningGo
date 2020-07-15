#include<iostream>
#include <algorithm> // sort
#include <map> // pair
using namespace std;
typedef unsigned long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
pair<int, bool> pair[102];
int main() {
    ll x, n;
    cin >> x >> n;
    bool p[102];
    rep(i, 102) p[i] = true;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        p[k] = false;
    }
    int ans;
    for (int i = 0; i < 102; i++) {
        if (p[x - i]) {
            ans = x - i;
            break;
        } else if (p[x + i]) {
            ans = x + i;
            break;
        }
    }
    cout << ans << endl;
}

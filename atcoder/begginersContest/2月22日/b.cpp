#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
ll n, k;
int main() {
    cin >> n >> k;
    ll ans, keep;
    keep = k;
    for (int i = 0; i < 30; i++) {
        if (n < keep) {
            ans = i;
            break;
        } else {
            keep *= k;
        }
    }
    cout << ans + 1 << endl;
}

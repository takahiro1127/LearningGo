#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
ll a[200000], ma[200000], mi[200000];
//計算結果で連想配列を作って、存在を確認すれば簡単だった。
int main() {
    ll n;
    cin >> n;
    ll count = 0;
    ll ain;
    for (ll i = 0; i < n; i++) {
        cin >> ain;
        ll k = i + 1 - ain;
        ma[i] = max(ma[i - 1], i + 1 + ain);
        mi[i] = min(mi[i - 1], i + 1 + ain);
        a[i] = i + 1 + ain;
        if (k < 1 || ma[i - 1] < k || mi[i - 1] > k) {
            continue;
        }
        for (int j = i - 1; j >= 0; j--) {
            if (ma[j] < k || mi[j] > k) {
                break;
            }
            if (k == a[j]) {
                count++;
            }
        }
    }
    cout << count << endl;
}

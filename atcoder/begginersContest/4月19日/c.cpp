#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
int main() {
    ll n, k;
    cin >> n >> k;
    if (n < k) {
        cout << min(n, k - n) << endl;
    } else if (n == k) {
        cout << 0 << endl;
    } else {
        ll l = n / k;
        cout << min(n - (l * k), ((l + 1) * k - n)) << endl;
    }
}

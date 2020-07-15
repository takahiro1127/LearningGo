#include<iostream>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)

int main() {
    ll x, y;
    cin >> x >> y;
    bool a = false;
    for(ll i = 0; i <= x; i++) {
        if (4 * i + 2 * (x - i) == y) {
            a = true;
        }
    }
    if (a) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

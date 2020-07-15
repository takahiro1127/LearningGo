#include<iostream>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
ll order(ll a) {
    int index = 1;
    for (int i = 0; ; i++) {
        if (a < 10) {
            break;
        }
        a /= 10;
        index++;
    }
    return index - 1;
}
int main() {
    ll n, a, b;
    a = 1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> b;
        if (order(b) + order(a) > 18) {
            a = -1;
            continue;
        }
        if (b == 0) {
            a = 0;
            break;
        }
        if (a == 0) {
            break;
        }
        if (a > 0 && a != -1) {
            a *= b;
        }
        if (a > 1000000000000000000) {
            a = -1;
        }
    }
    if (a > 1000000000000000000) {
        a = -1;
    }
    cout << a << endl;
}

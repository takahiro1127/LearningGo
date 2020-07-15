#include<iostream>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
int main() {
    ll k;
    cin >> k;
    ll a, b;
    cin >> a >> b;
    bool t = false;
    for (int c = a; c<= b; c++) {
        if (c % k == 0) {
            t = true;
            break;
        }
    }
    if (t) {
        cout << "OK" << endl;
    } else {
        cout << "NG" << endl;
    }
}

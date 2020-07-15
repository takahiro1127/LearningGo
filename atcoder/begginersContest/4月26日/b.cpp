#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
int main() {
    ll a, b, c, d, e, f;
    cin >> a >> b >> c >> d;
    ll counta, countb;
    countb = a/d;
    e = a % d;
    counta = c/b;
    f = c % b;
    if (e == 0) {
        countb--;
    }
    if (f == 0) {
        counta--;
    }
    if (counta <= countb) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

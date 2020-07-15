#include<iostream>
using namespace std;
typedef unsigned long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
int main() {
    ll a, k;
    double b;
    cin >> a >> b;
    if (a != 0 && b != 0) {
        k = b * 1000;
        a *= k;
        a /= 1000;
        cout << a << endl;
    } else {
        cout << 0 << endl;
    }
}

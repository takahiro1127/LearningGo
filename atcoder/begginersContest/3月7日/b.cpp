#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
ll n, a, b;
int main() {
    cin >> n >> a >> b;
    ll k = n / (a + b);
    ll r = n % (a + b);
    if (r > a) {
        cout << k * a + a << endl;
    } else {
        cout << k * a + r << endl;
    }
}

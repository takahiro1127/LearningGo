#include<iostream>
#include<vector>
#include <algorithm>
#include <map> // pair
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
int main() {
    ll a, b, c, k;
    cin >> a >> b >> c >> k;
    if (a >= k) {
        cout << k << endl;
    } else if (a + b >= k) {
        cout << a << endl;
    } else {
        cout << a - (k - (a + b)) << endl;
    }
}

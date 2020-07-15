#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
int main() {
    ll n, m;
    double sum = 0;
    cin >> n >> m;
    ll a[n];
    rep(i, n) cin >> a[i];
    rep(i, n) sum += a[i];
    sort(a, a + n);
    double border = sum / (4 * m);
    if (a[n - m] < border) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
}

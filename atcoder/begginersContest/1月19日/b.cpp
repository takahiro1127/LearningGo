#include<iostream>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    int n, m;
    cin >> n >> m;
    string a, b;
    rep(i, n) a += to_string(m);
    rep(i, m) b += to_string(n);
    if (a < b) {
        cout << a << endl;
    } else {
        cout << b << endl;
    }
}

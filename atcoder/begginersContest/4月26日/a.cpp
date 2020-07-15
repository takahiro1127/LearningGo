#include<iostream>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
int main() {
    ll a, b;
    cin >> a >> b;
    if (b >= a) {
        cout << "unsafe" << endl;
    } else {
        cout << "safe" << endl;
    }
}

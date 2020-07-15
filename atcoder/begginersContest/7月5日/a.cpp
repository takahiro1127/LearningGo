#include<iostream>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
int main() {
    ll a;
    cin >> a;
    if (a%1000 == 0) {
        cout << 0 << endl;
    } else {
        cout << 1000 - a%1000 << endl;
    }
}

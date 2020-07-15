#include<iostream>
#include<vector>
#include <queue>
#include <string>
using namespace std;
typedef unsigned long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
int main() {
    ll a, b, n;
    cin >> a >> b >> n;
    if (b <= n) {
        cout << (a * (b - 1)) / b << endl;
    } else {
        cout << (a * n) / b << endl;
    }
}

#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
int main() {
    ll x;
    cin >> x;
    ll k = 100;
    ll count = 0;
    for (; k < x; k *= 1.01) {
        count++;
    }
    cout << count << endl;
}

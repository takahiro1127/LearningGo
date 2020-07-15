#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
ll n, r;
int main() {
    cin >> n >> r;
    if (n >= 10) {
        cout << r << endl;
    } else {
        cout << r + 100 * (10 - n) << endl;
    }
}

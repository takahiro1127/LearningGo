#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
ll n, a, b;
int main() {
    cin >> a >> b;
    int amin, bmin;
    amin = ((a * 100) / 8) + 1;
    bmin = ((b * 100) / 10) + 1;
    if ((a * 100) % 8 == 0) {
        amin = ((a * 100) / 8);
    }
    if ((b * 100) % 10 == 0) {
        bmin = ((b * 100) / 10);
    }
    int amax, bmax;
    amax = (((a + 1) * 100) / 8);
    bmax = (((b + 1) * 100) / 10);
    if (((a+1) * 100) % 8 == 0) {
        amax = (((a + 1) * 100) / 8) - 1;
    }
    if (((b+1) * 100) % 10 == 0) {
        bmax = (((b + 1) * 100) / 10) - 1;
    }
    if (amax < bmin || bmax < amin) {
        cout << "-1" << endl;
    } else {
        cout << max(amin, bmin) << endl;
    }
}

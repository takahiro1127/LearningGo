#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
int n;
double t = 1000000000;
double x[100];
int main() {
    cin >> n;
    rep(i, n) cin >> x[i];
    for (int i = 0; i < 100; i++) {
        double g = 0;
        rep(k, n) g += (x[k] - i) * (x[k] - i);
        t = min(t, g);
    }
    cout << t << endl;
}

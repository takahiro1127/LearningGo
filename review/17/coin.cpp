#include<iostream>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
int n, m;
int c[20];
int t[20][50000];
int main() {
    cin >> n >> m;
    int minC = 0;
    rep(i, m) cin >> c[i], minC = min(minC, c[i]);
    t[0][minC] = 1;
    for (int i = 1; i < m; i++) {
        for (int j = 0; j < n; j++) {
            t[i][j] = min(t[i - 1][j], t[i][j - c[i]] + 1);
        }
    }
}

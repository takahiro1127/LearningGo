#include<iostream>
#include<vector>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
int lcs(int, int);
int l[100][100];
string s, t;
int main() {
    int n;
    cin >> n;
    rep(i, n) cin >> s[i];
    rep(i, n) cin >> t[i];
    l[0][0] = 0;
    rep(i, n) rep(j, n) lcs(i, j)
}

int lcs(int i, int j) {
    if (s[i] == t[j]) {
        l[i][j] = l[i - 1][j - 1] + 1;
    } else {
        l[i][j] = max(l[i - 1][j], l[i][j - 1]);
        // 比べてる二つが違う場合、片方の長さをちぢめてもlcsには影響がないから
    }
}

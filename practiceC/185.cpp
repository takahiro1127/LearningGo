#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map> // ヘッダファイルインクルード
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

std::vector<std::vector<long long> > comb(int n, int r) {
    std::vector<std::vector<long long> > v(n + 1,std::vector<long long>(n + 1, 0));
    for (int i = 0; i < v.size(); i++) {
        v[i][0] = 1;
        v[i][i] = 1;
    }
    for (int j = 1; j < v.size(); j++) {
        for (int k = 1; k < j; k++) {
        v[j][k] = (v[j - 1][k - 1] + v[j - 1][k]);
        }
    }
    return v;
}

int main() {
    int l;
    cin >> l;
    vector<vector<ll> > v = comb(l - 1, 11);
    cout << v[l - 1][11] << endl;
}
#これはかなり時間があいてしまったため、答えを見ることにした

#include<iostream>
using namespace std;
int N, K;
bool S[100000];
void change(int, int);
int main() {
    cin >> N >> K;
    string s;
    cin >> s;
    for (int i = 0; i < N; i++) {
        if (s[i] == 'R') {
            S[i] = true;
        } else {
            S[i] = false;
        }
    }
    change(2, 4);
    for (int i = 0; i < N; i++) {
        if (S[i]) {
            cout << "R" << endl;
        } else {
            cout << "L" << endl;
        }
    }
}

//これはcopyした奴
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

int main() {

    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    ll ans = 0;
    // まず、初期状態で幸せな人の人数を調べている
    rep(i, n - 1) {
        if (s[i] == s[i + 1]) ans++;
    }
    // k回の作業で2*k人を幸せにできる。
    ans += 2 * k;
    // 幸せにできる人数の最大数はn-1人なので、小さい方が幸せの最大値になる。
    cout << min(n - 1, ans) << '\n';
    return 0;
}

// LLLLLLLRRRRRLLLLLRRRRLLLLLL
// について、反転しても端っこの部分しか変わらず、挟まれている場合必ず+2される
// +1になるのは最後の段階のみ

// N人が並んでいて、RまたはLを見ている
// 目の前の人が自分と同じ方向を見ていたら幸せ
// K回次の操作を行うことができる
// 1 <= l <= r <= N を満たすl, rを決める
// l~rまでの人を列ごと回転させる
// 1 R, 2 L, 3, R
// →　3 L, 2 R, 1 L
//最大で何人幸せにできるか
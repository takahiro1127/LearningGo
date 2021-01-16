#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map> // ヘッダファイルインクルード
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
// 約数列挙
vector<long long> divisor(long long n) {
    vector<long long> ret;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            // i * n / iでnになるので、iを入れ、n/iを次にいれる
            if (i * i != n) ret.push_back(n / i);
        }
    }
    sort(ret.begin(), ret.end()); // 昇順に並べる
    return ret;
}

int main() {
    ll n;
    cin >> n;
    ll count = 0;
    // for (int i = 1; i < n ; i++) {
    //     vector<ll> divisors = divisor(n - i);
    //     ll length = divisors.size();
    //     count += (length / 2) * 2 + length % 2;
    // }
    // Aを固定するとBはN/A個存在する
    // Cは自動的に定まる。
    // Cが必ず1より大きくなる様にn - 1で考える
    // A = 1からn - 1まで考える。

    // どの数を固定するかを早めに決定しない
    for (int i = 1; i < n; i++) {
        // cが少なくとも1であるため
        count += (n - 1) / i;
    }
    cout << count << endl;
}
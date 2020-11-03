#include <iostream>
#include <algorithm>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
#define MAX_COUNT 1000;
int l[MAX_COUNT];
// 二分木と貪欲砲greedyを組み合わせたアルゴリズム
//　蟻本のp50のfence repair

void solve(int n) {
    sort(l, l + n);
    ll ans = 0;
    while (n > 1) {
        sort(l, l + n);
        int min1 = 0, min2 = 1;
        int t = l[min1] + l[min2];
        // ...みたいな感じでやっていく
    }
}

int main() {
    int n;
    cin >> n;
    rep(i, n) l[i] = i;
    solve(n);
}
- 全列挙も可能性に入れて考える。
- 動的計画法を考える時はどれを数列にするかをよく考える
- 誤答をアップするのは非常によくない、デバックのつもりでぽんぽん投げないこと
これを使おう
#include<iostream>
#include<vector>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    std::vector<int> p(n);
    rep(i, n) cin >> p[i];
}



- next_permutation 次の順列を返す　https://cpprefjp.github.io/reference/algorithm/next_permutation.html

- gcd 
ll gcd(ll a, ll b) {return b?gcd(b, a%b):a;}
- lcm
ll lcm(ll a, ll b) {return a/gcb(a, b) * b;}
- 偶奇を考える
- 2の階乗を考える
## next level
- shift演算子

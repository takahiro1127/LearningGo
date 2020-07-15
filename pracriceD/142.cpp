#pragma GCC optimize("Ofast")
#include <iostream>
typedef long long ll;
int a, b;
ll gcd(ll , ll);
int main() {
    std::cin >> a >> b;
    int c = gcd(a, b);
    int count = 0;
    for (int i = 2; i <= c; i++) {
        if (c % i == 0) {
            count++;
            for (;c % i == 0;) {
                c /= i;
            }
        }
    }
    std::cout << count+1 << std::endl;
}
ll gcd(ll x, ll y) {
    return y ? gcd(y, x % y) : x;
}


// aとbについて正の公約数からいくつか選ぶ
// このとき選んだ公約数はお互いに素である必要がある
// 最大で何個選べるか
// 小さい方を素因数分解してそれぞれの素数が大きい方を割り切れるかを確かめる→素因数分解がまずむずい
// gcdで最大公約数を見つける
// 最大公約数を素因数分解したい
// 最大公約数の素因数分解というアプローチは間違っていないのに、素因数分解の数え上げ部分でTLEになってしまうのはなぜ？？

#include<iostream>
using namespace std;
long int n;
int main() {
    cin >> n;
    if (n % 2 == 1 || n < 10) {
        cout << 0 << endl;
        return 1;
    }
    long int count = 0;
    long int k = 1;
    for (long int i = 10; i <= n; i *= 10) {
        long int m = n / i;
        count += m;
        if (k * 10 < n) {
            long int j = pow(5, k) * 10;
            
        }
    }
    cout << count << endl;
}
//このループのなかで2の倍数と5の倍数のでる回数を数えればいい
//ってか10の倍数の数だけ数えればいいけど、
//例えば100の時に11になるみたいに100の倍数が重なる時があるので、それを注意しながらって考えると
//ここで気づいたのが、20と50の倍数みたいなやつ
//ってか250の倍数とか1250の倍数の数も数えて、足していってあげなきゃいけない

#include <iostream>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)
ll sumBet(ll a, ll b) {
    ll asum = a * (a + 1) / 2;
    ll bsum = b * (b + 1) / 2;
    return bsum - asum + a;
}
int main()
{
    ll n;
    cin >> n;
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        sum += sumBet(a, b);
    }
    cout << sum << endl;
}

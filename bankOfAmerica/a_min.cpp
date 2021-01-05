#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ll n;
    cin >> n;
    ll sum = n * (n + 1) / 2;
    cout << sum << endl;
    ll five_sum, seven_sum;
    ll five_div = n / 5;
    five_sum = (five_div + 1) * (five_div * 5) / 2;
    cout << five_sum << endl;
    ll seven_div = n / 7;
    seven_sum = (seven_div + 1) * (seven_div * 7) / 2;
    cout << seven_sum << endl;
    cout << sum - five_sum - seven_sum << endl;
}
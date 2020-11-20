#include <iostream>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)
ll l[200000];
ll l_sum[200000];
ll max_l_mem[200000];
ll n;
int main()
{
    cin >> n;
    cin >> l[0];
    ll zero = 0;
    max_l_mem[0] = max(l[0], zero);
    for (int i = 1; i < n; i++) {
        ll a;
        cin >> a;
        l[i] = l[i - 1] + a;
        max_l_mem[i] = max(l[i], max_l_mem[i - 1]);
    }
    l_sum[0] = l[0];
    for (int i = 1; i < n; i++) {
        l_sum[i] = l_sum[i - 1] + l[i];
    }
    ll max_l = l_sum[n - 1];
    for (int i = 1; i < n; i++) {
        max_l = max(max_l, max_l_mem[i] + l_sum[i - 1]);
        // if (l_sum[i - 1] > l_sum[i]) {
        //     max_l = max(max_l, l_sum[i - 1] + max_l_mem[i - 1]);
        // } else if (l_sum[i - 1] < l_sum[i]) {
        //     max_l = max(max_l, l_sum[i - 1] + max_l_mem[i - 1]);
        // }
    }
    cout << max_l << endl;
}

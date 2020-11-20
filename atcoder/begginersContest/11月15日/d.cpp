#include <iostream>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)
ll n, w;
ll time_sche[200000];
int main()
{
    rep(i, 200000) time_sche[i] = 0;
    cin >> n >> w;
    bool ans = true;
    for (int i = 0; i < n; i++) {
        int s, t;
        ll p;
        cin >> s >> t >> p;
        for (int j = s; j < t; j++) {
            time_sche[j] += p;
            if (time_sche[j] > w) {
                ans = false;
                break;
            }
        }
    }
    if (ans) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    // s~t(tちょうどを除く)の間に、Σpを超えるか
}

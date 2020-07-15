#include<iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
int main() {
    ll maxi = -1;
    ll mini = 101;
    ll sum = 0;
    for (int i = 0; i < 7; i++) {
        ll t;
        cin >> t;
        maxi = max(t, maxi);
        mini = min(t, mini);
        sum += t;
    }
    sum -= maxi;
    sum -= mini;
    cout << sum / 5 << endl;
}

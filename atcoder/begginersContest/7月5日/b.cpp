#include<iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)

int main() {
    ll n;
    cin >> n;
    ll ac = 0;
    ll wa = 0;
    ll re = 0;
    ll tle = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s == "AC") {
            ac++;
        } else if (s == "WA") {
            wa++;
        } else if (s == "RE") {
            re++;
        } else if (s == "TLE") {
            tle++;
        }
    }
    cout << "AC x " << ac << endl;
    cout << "WA x " << wa << endl;
    cout << "TLE x " << tle << endl;
    cout << "RE x " << re << endl;
}

#include<iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)

int main() {
    string s, t;
    cin >> s;
    cin >> t;
    ll n = s.size();
    ll count = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            count++;
        }
    }
    cout << count << endl;
}

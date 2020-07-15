#include<iostream>
#include<vector>
#include <queue>
#include <string>
using namespace std;
typedef unsigned long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
int main() {
    string s;
    cin >> s;
    ll count = 0;
    ll n = s.size();
    for (int i = 0; i < n - 3; i++) {
        //20万文字の場合llに収まりきらない
        string k = s.substr(i, n - i);
        ll len = k.size();
        if (len < 10) {
            ll t = stoll(k);
            for (;t >= 12114; t /= 10) {
                if (t % 2019 == 0) {
                    count++;
                }
            }
        } else {
            
        }
    }
    cout << count << endl;
}

#include<iostream>
#include<vector>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
int main() {
    ll n;
    std::map<std::string, bool> mp;
    string s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        mp[s] = true;
    }
    cout << mp.size() << endl;
}

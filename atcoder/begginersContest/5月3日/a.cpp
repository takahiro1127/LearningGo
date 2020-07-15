#include<iostream>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
int main() {
    string s, t;
    cin >> s;
    cin >> t;
    int n = s.size();
    t.erase(n);
    if (t == s) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

#include<iostream>
#include <algorithm>
#include <stack>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)

int main() {
    ll n;
    cin >> n;
    ll m = 0;
    stack<ll> st;
    string querys[n];
    rep(i, n) cin >> querys[i];
    for (ll i = 0; i < n; i++) {
        if (querys[i] == "add") {
            m += 1;
        } else if (querys[i] == "pin") {
            st.push(m);
        } else if (querys[i] == "rollback") {
            if (st.empty()) {
                cout << "invalid query" << endl;
            }
            m = st.top();
            st.pop();
        } else if (querys[i] == "print") {
            cout << m << endl;
        }
    }
}

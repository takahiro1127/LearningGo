#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main()
{
    string s;
    cin >> s;
    stack<int> S1;
    stack<pair<int, int>> S2;
    char ch;
    int sum = 0;
    for (int i = 0; cin >> ch; i++) {
        if (ch == "\\") {
            S1.push(i);
        } else if (ch == '/' && S1.size() > 0) {
            int j = S1.top();
            S1.pop();
            sum += i - j;
            int a = i - j;
            while (S2.size() > 0 && S2.top().first() > j) {
                a += S2.top().second();
                S2.pop();
            }
            S2.push(make_pair(j, a))
        }
    }
    vector<int> ans;
    while(S2.size() > 0) {
        ans.push_back(S2.top.second());
        S2.pop()
    }
    reverse(ans.begin(), ans.end());
    cout << sum << endl;
}
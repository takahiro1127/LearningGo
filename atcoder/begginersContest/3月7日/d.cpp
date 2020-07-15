#include<iostream>
#include <sstream>
#include<vector>
#include <algorithm>
#include <string>
#include <list>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
ll q;
string s;
list<string> lst;
int main() {
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        string k = s[i];
        lst.push_back(s[i]);
    }
    cin >> q;
    int t, f;
    char c;
    bool r = false;
    for (int i = 0; i < q; i++) {
        cin >> t;
        if (t == 1) {
            r = !r;
        } else {
            cin >> f;
            cin >> c;
            if ((f == 1 && !r) || (f == 2 && r)) {
                lst.push_front(c);
            } else {
                lst.push_back(c);
            }
        }
    }
    if (r) {
        for(auto itr = lst.end(); itr != lst.begin(); --itr) {
            std::cout << *itr;
        }
    } else {
        for(auto itr = lst.begin(); itr != lst.end(); ++itr) {
            std::cout << *itr;
        }
    }
}

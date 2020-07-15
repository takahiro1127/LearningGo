#include<iostream>
using namespace std;
int n;
string s, t;
int main() {
    cin >> n;
    cin >> s >> t;
    string out = "";
    for (int i = 0; i < n; i++) {
        out += s[i];
        out += t[i];
    }
    cout << out << endl;
}

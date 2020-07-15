#include<iostream>
using namespace std;
int n;
string x;
string s[50];
int t[50];
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i] >> t[i];
    }
    cin >> x;
    int k;
    for (int i = 0; i < n; i++) {
        if (s[i] == x) {
            k = i;
            break;
        }
    }
    int sum = 0;
    for (int i = k + 1; i < n; i++) {
        sum += t[i];
    }
    cout << sum << endl;
}

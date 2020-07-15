#include<iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    int count, n;
    n = s.length();
    count = 0;
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - 1  - i]) {
            count++;
        }
    }
    cout << count << endl;
}

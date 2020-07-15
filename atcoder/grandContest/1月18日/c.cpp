#include<iostream>
using namespace std;
int n, k;
long int s;
int main() {
    cin >> n >> k >> s;
    int a[n];
    if (s != 1000000000) {
        for (int i = 0; i < n; i++) {
            if (i < k) {
                a[i] = s;
            } else {
                a[i] = s + 1;
            }
        }
    } else {
        for (int i = 0; i < n; i++) {
            if (i < k) {
                a[i] = s;
            } else {
                a[i] = 1;
            }
        }
    }
    string s;
    for (int i = 0; i < n; i++) {
        s += to_string(a[i]);
        s += ' ';
    }
    cout << s << endl;
}

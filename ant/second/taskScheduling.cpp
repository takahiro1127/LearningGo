#include<iostream>
using namespace std;
int join(int, int[], int[], int, int, int);
int main() {
    int n, c;
    c = 0;
    cin >> n;
    int s[n], f[n];
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> f[i];
    }
    cout << join(-1, s, f, 0, c, n) << endl;
}

int join(int t, int s[], int f[], int p, int c, int n) {
    if (p == n) {
        return c;
    }
    if (t < s[p]) {
        c = max(join(f[p], s, f, p+1, c+1, n), join(t, s, f, p+1, c, n));
    } else {
        c = join(t, s, f, p+1, c, n);
    }
    return c;
}
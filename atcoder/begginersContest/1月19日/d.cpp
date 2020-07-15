#include<iostream>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
int n, k, s, a, x;
string temp;
int comb(int, int);
int pow(int, int);
int main() {
    cin >> n;
    s = 0;
    for (int i = 10; i <= n; i *= 10) {
        s++;
    }
    a = n % 10;
    k = n / pow(10, s);
    x = n / 10 - k * pow(10, s - 1);
    ll count = 0;
    for (int i = 1; i < 10; i++) {
        for (int j = 1; j < 10; j++) {
            count += (comb(i, j) * comb(j, i));
        }
    }
    cout << count << endl;
}

int comb(int i, int j) {
    if(i < k) {
        if (i == j) {
            return pow(10, s - 1) + 2;
        }
        return pow(10, s - 1) + 1;
    } else if (i > k) {
        if (i == j) {
            return pow(10, s - 2) + 2;
        }
        return pow(10, s - 2) + 1;
    } else {
        if (a <= j) {
            if (i == j) {
                return x + 3;
            }
            return x + 2;
        } else {
            if (i == j) {
                return x + 2;
            }
            return x + 1;
        }
    }
}

int pow(int x, int y) {
    int ans = 1;
    for (int i = 0; i < y; i++) {
        ans *= x;
    }
    return ans;
}

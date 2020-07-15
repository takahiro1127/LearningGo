#include<iostream>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
int n;
int p[200000];
int main() {
    cin >> n;
    rep(i, n) cin >> p[i];
    int count = 1;
    int min = p[0];
    for (int i = 1; i < n; i++) {
        if (min >= p[i]) {
            min = p[i];
            count++;
        }
    }
    cout << count << endl;
}

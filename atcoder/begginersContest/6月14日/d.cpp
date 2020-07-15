#include<iostream>
#include <algorithm> // sort
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
int main() {
    int n;
    cin >> n;
    bool ans[200000];
    int a[200000];
    int count = n;
    rep(i, n) cin >> a[i];
    sort(a, a+n); // 配列
    for (int i = 0; i < n && count != 0; i++) {
        if (i >= 1 && a[i] == a[i - 1] && !ans[i - 1]) {
            count--;
            continue;
        }
        if (ans[i]) {
            continue;
        }
        for (int j = i + 1; j < n && count != 0; j++) {
            if (ans[j]) {
                continue;
            }
            if (a[j] % a[i] == 0) {
                if (!ans[j]) {
                    count--;
                }
                ans[j] = true;
            }
        }
    }
    cout << count << endl;
}

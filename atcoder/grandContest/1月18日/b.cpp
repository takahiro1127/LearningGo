#include<iostream>
#include <algorithm> // sort
#include <map> // pair
using namespace std;
int n;
int s[100000], f[100000];
pair<int, int> itv[100000];
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, l;
        cin >> x >> l;
        s[i] = x - l;
        f[i] = x + l;
    }
    for (int i = 0; i < n; i++) {
        itv[i].first = f[i];
        itv[i].second = s[i];
    }
    sort(itv, itv + n);
    int ans = 0, t = itv[0].second - 10;
    for (int i = 0; i < n; i++) {
        if (t <= itv[i].second) {
            ans++;
            t = itv[i].first;
        }
    }
    cout << ans << endl;
}

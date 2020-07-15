#include<iostream>
#include<vector>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
ll n, m, x;
ll c[12], a[12][12], maxsum[12];
bool check(bool l[]) {
    ll skill[m];
    for (int j = 0; j < m; j++) {
        skill[j]  = 0;
    }
    for (int i = 0; i < n; i++) {
        if (l[i]) {
            for (int j = 0; j < m; j++) {
                skill[j] += a[i][j];
            }
        }
    }
    bool check = true;
    for (int j = 0; j < m; j++) {
        if (skill[j] < x) {
            check = false;
            break;
        }
    }
    return check;
}

ll costSum(bool l[]) {
    if (check(l)) {
        ll count = 0;
        for (int i = 0; i < n; i++) {
            if (l[i]) {
                count += c[i];
            }
        }
        return count;
    } else {
        return 1300000;
    }
}
ll search(bool l[], ll p) {
    if (p == n) {
        return costSum(l);
    } else {
        bool copyl[n], copyl2[n];
        for (int i = 0; i < n; i++) {
            if (l[i]) {
                copyl[i] = true;
                copyl2[i] = true;
            } else {
                copyl[i] = false;
                copyl2[i] = false;
            }
        }
        copyl2[p] = true;
        p++;
        ll g = search(copyl, p);
        ll o = search(copyl2, p);
        return min(g, o);
    }
}

int main() {
    cin >> n >> m >> x;
    for (int j = 0; j < m; j++) {
        maxsum[j] = 0;
    }
    for (ll i = 0; i < n; i++) {
        cin >> c[i];
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            maxsum[j] += a[i][j];
        }
    }
    bool check = true;
    for (int j = 0; j < m; j++) {
        if (maxsum[j] < x) {
            check = false;
            break;
        }
    }
    if (!check) {
        cout << -1 << endl;
    } else {
        bool l[n];
        rep(i, n) l[i] = false;
        cout << search(l, 0) << endl;
    }
}

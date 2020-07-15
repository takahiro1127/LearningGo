#include<iostream>
#include<vector>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
int a[50], b[50], c[50];
ll d[50];
int n, m, q;
int sum(int k[]) {
    ll sum = 0;
    for (int i = 0; i < q; i++) {
        if (k[b[i]] - k[a[i]] == c[i]) {
            sum += d[i];
        }
    }
    return sum;
}

int search(int k[]) {
    int ans = sum(k);
    for (int j = 1; j <= n; j++) {
        for (int i = 2; i <= max(m, k[n - j + 1]); i++) {
            k[n - j] = i;
            ans = max(ans, sum(k));
        }
    }
    return ans;
}

int main() {
    cin >> n >> m >> q;
    for (int i = 0; i < q; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    int k[n + 1];
    for (int i = 0; i < n + 1; i++) {
        k[i] = 1;
    }
    cout << search(k) << endl;
}

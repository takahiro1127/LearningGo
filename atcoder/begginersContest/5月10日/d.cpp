#include<iostream>
#include<vector>
#include <queue>
#include <string>
using namespace std;
typedef long long ll;
typedef unsigned long ul;
#define rep(i, n) for(int i = 0; i < (n); i++)
ul k, n;
ll a[200000];
int main() {
    cin >> n >> k;
    ll visited[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        visited[i] = -1;
    }
    if (n >= k) {
        ll position = 0;
        for (ll i = 0; i < k; i++) {
            position = a[position];
        }
        cout << position << endl;
    } else {
        ul position = 0;
        ul roop;
        ul when[n];
        for (ll i = 0; i <= n; i++) {
            if (visited[position] < 0) {
                visited[position] = i;
                when[i] = position;
                position = a[position] - 1;
            } else {
                roop = i - visited[position];
                break;
            }
        }
        ul afterRoop = (k - visited[position]) % roop;
        cout << when[visited[position] + afterRoop] + 1 << endl;
    }
}

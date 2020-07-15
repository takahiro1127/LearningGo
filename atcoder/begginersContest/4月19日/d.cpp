#include<iostream>
#include<vector>
#include <queue>
using namespace std;
typedef long long ll;
ll count = 0;
#define rep(i, n) for(int i = 0; i < (n); i++)
int nextNumber(int);
int main() {
    ll k;
    cin >> k;
    queue<int> q;
    ll result = 0;
    for (int i = 1; i <= k) {
        ll r;
        ll a = q.front();
        int t = r  - (r / 10) * 10;
        q.push(a * 10)
    }
    q.
}

int nextNumber(int r) {
    int t = r  - (r / 10) * 10;
    if (count == 0) {
        count++;
        if (t != 0) {
            return r * 10 + t - 1;
        } else {
            return r * 10;
        }
    } else if (count == 1) {
        if (t == 9 || t == ) {
            count = 0;
        }
        count++;
        return r * 10 + t;
    } else if (count == 2) {
        count = 0;
    }
    
}

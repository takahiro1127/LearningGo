#include<iostream>
#include<map>
using namespace std;
typedef unsigned long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
ll kount(ll cou) {
    ll index = 0;
    for (ll i = 1; ;i++) {
        if (cou < i) {
            break;
        } else {
            cou -= i;
            index++;
        }
    }
    return index;
}
map<ll, ll> prime_factor(ll n) {
map< ll, ll > ret;
  for(ll i = 2; i * i <= n; i++) {
        while(n % i == 0) {
            ret[i]++;
            n /= i;
        }
    }
if(n != 1) ret[n] = 1;
return ret;
}
int main() {
    ll n, c;
    map<ll, ll> count;
    cin >> n;
    count = prime_factor(n);
    ll cc = 0;
    for (map<ll, ll>::iterator i = count.begin(); i != count.end(); ++i){
        cc += kount(i->second);
    }
    cout << cc << endl;
}

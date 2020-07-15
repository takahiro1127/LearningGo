#include<iostream>
#include <algorithm> // sort
#include <map> // pair
#include<vector>
using namespace std;
typedef unsigned long long ll;
#define rep(i, n) for(ll i = 0; i < (n); i++)
vector<ll> ansk[10000001];
bool anskb[10000001];
ll count(ll n) { 
    ll ans = 1;

	vector<ll> x(n + 1);
	ll num = n;

	for (ll i = 2; i <= n; i++) {
		while (num%i == 0) {
			x.at(i)++;
			num /= i;
            if (anskb[num]) {
                for (ll j = 2; j <= num; j++)
                {	
                    x.at(j) += ansk[num].at(j);
                }
                goto OUT;
                break;
            }
		}
	}
OUT:

	for (ll i = 2; i <= n; i++)
	{	
		ans *= x.at(i) + 1;
	}
    ansk[n] = x;
    anskb[n] = true;
	return ans;
}
int main() {
    ll n;
    cin >> n;
    ll ans = 0;
    for (ll i = 1; i <= n; i++) {
        ans += i * count(i);
    }
    cout << ans << endl;
}

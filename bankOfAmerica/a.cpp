#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); ++i)
ll pow(ll base, ll index) {
  ll ans = 1;
  rep(i, index) ans *= base;
  return ans;
}
int main() {
  string line;
  while (getline(cin, line)) {
    ll n = stoi(line);
    ll sevens = n / 7;
    ll minus_sevens =  7 * (pow(7, sevens) - 1)/6;
    ll fives = n / 5;
    ll minus_fives =  5 * (pow(5, fives) - 1)/4;
    cout << n * (n - 1)/2 - minus_sevens - minus_fives << endl;
  }
}
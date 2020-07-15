#include<iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)

int main() {
    ll n, m, k;
    ll a[200000], b[200000];
    cin >> n >> m >> k;
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];
    ll nc = 0;
    ll mc = 0;
    ll tim = 0;
    ll ans = 0;
    //まずは、aのみを読む
    for (;tim <= k;) {
      //次の一冊いけますか？？
      ll ttim = tim + a[nc];
      if (ttim <= k) {
        ans++;
        nc++;
        tim = ttim;
        if (nc == n) {
          break;
        }
      } else {
        break;
      }
    }
    for (;;) {
      //bの次の一冊いけますか
      ll ttim = tim + b[mc];
      if (ttim <= k) {
        ans++;
        mc++;
        tim = ttim;
        if (mc == m) {
          break;
        }
      } else {
        break;
      }
    }
    if (ans != 0) {
      //nc冊目, mc冊目までいけることが確定している。
      for (;;) {
        //nc番目の本減らして、mc+1番目を追加する
        tim = tim - a[nc - 1] + b[mc];
        if (tim <= k) {
          //いけたらans更新
          ans = max(ans, mc + nc);
        } 
        nc--;
        mc++;
        //mcがmに到達もしくはncが0に到達で抜ける
        if (mc == m || nc == 0) {
          break;
        }
      }
    }
    ll btim = 0;
    ll boc = 0;
    ll bans = 0;
    for (;btim <= k;) {
      //次の一冊いけますか？？
      ll ttim = btim + b[boc];
      if (ttim <= k) {
        bans++;
        boc++;
        btim = ttim;
        if (boc == m) {
          break;
        }
      } else {
        break;
      }
    }
    ans = max(ans, bans);
    cout << ans << endl;
}

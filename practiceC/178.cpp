#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map> // ヘッダファイルインクルード
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
// これは、答えを見るまでわからなかった。
// わからない時はベン図を書いてみよう
const ll mod=1000000007;
ll powmod(ll x,ll y){
    ll res=1;
    for(ll i=0;i<y;i++){
        res=res*x%mod;
    }
    return res;
}
int main(){
    ll n;
    cin>>n;
    ll ans=powmod(10,n)-powmod(9,n)-powmod(9,n)+powmod(8,n);
    ans%=mod;
    ans=(ans+mod)%mod;
    cout<<ans<<"\n";
}
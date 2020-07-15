#include<iostream>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
int main() {
    ll a;
    cin >> a;
    ll b = a + a * a + a * a * a;
    cout << b << endl;
}

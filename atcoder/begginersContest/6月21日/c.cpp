#include<iostream>
#include <sstream>
#include<string>
#include <map> // pair
using namespace std;
typedef unsigned long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
class Radix {
private:
  const char* s;
  int a[128];
public:
  Radix(const char* s = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ") : s(s) {
    int i;
    for(i = 0; s[i]; ++i)
      a[(int)s[i]] = i;
  }
  std::string to(long long p, int q) {
    int i;
    if(!p)
      return "0";
    char t[64] = { };
    for(i = 62; p; --i) {
      t[i] = s[p % q];
      p /= q;
    }
    return std::string(t + i + 1);
  }
  std::string to(const std::string& t, int p, int q) {
    return to(to(t, p), q);
  }
  long long to(const std::string& t, int p) {
    int i;
    long long sm = a[(int)t[0]];
    for(i = 1; i < (int)t.length(); ++i)
      sm = sm * p + a[(int)t[i]];
    return sm;
  }
};
int main() {
    Radix r;
    ll n;
    cin >> n;
    string s = r.to(n - 1, 26);
    const char*  alpha = "abcdefghijklmnopqrstuvwxyz";
    const char*  beta = "0123456789ABCDEFGHIJKLMNOP";
    std::map<char, char> mp, lmp;
    for(int i = 0; i < 26; i++) {
        mp[beta[i]] = alpha[i];
        if (i > 0) {
            lmp[beta[i]] = alpha[i - 1];
        } else {
            lmp[beta[i]] = alpha[0];
        }
    }
    int l = s.size();
    for(int i = 0; i < l; i++) {
        if (i == l - 1) {
            s[i] = mp[s[i]];
        } else {
            s[i] = lmp[s[i]];
        }
    }
    cout << s << endl;
}

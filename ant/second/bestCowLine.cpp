#include<iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  string s, t;
  cin >> s;
  t = "";
  int r, l;
  l = 0;
  r = n - 1;
  for (int i = 0; i < n; i++) {
    if (s[l] > s[r]) {
      t = t + s[r];
      s.erase(r, 1);
      cout << s << endl;
      r -= 1;
    }
    else if (s[r] > s[l]) {
      t = t + s[l];
      s.erase(r, 1);
      l += 1;
    } else {
      string rCopy;
      reverse_copy(s.begin(), s.end(), back_inserter(rCopy));
      // cout << rCopy << endl;
      if (s > rCopy) {
        t = t + s[r];
        s.erase(r, 1);
        r -= 1;
      } else {
        t = t + s[l];
        s.erase(r, 1);
        l += 1;
      }
    }
  }
  cout << t << endl;
}

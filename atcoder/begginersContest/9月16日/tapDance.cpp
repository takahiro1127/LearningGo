#include<iostream>
using namespace std;

int main() {
  string s;
  int n;
  bool easy = true;
  cin >> s;
  n = s.size();
  for (int i = 0; i < n; i = i + 2) {
    if (s[i] == 'L') { easy = false;}
  }
  for (int i = 1; i < n; i = i + 2) {
    if (s[i] == 'R')
    {
      easy = false;
    }
  }
  fputs(easy ? "Yes" : "No", stdout);
}

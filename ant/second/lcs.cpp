#include<iostream>
using namespace std;
int lcs(string, int, string, int, int[][], int);

int main() {
  string s, t;
  cin >> s >> t;
  int mem[s.length()][t.length()];
  for (int i = 0; i < s.length(); i++) {
    for (int j = 0; j < t.length(); j++) {
      mem[i][j] = 0;
    }
  }
  cout << lcs(s, 0, t, 0, mem, 0) << endl;
}

int lcs(string s, int i, int lenS, string t, int j, int lenT, int mem[][lenT], int len) {
  if (mem[i][j] != 0) {
    return mem[i][j];
  }
  if(s.length() == i - 1 || t.length() == j - 1) {
    return len;
  }
  int maxLength;
  if (s[i] == t[j]) {
    maxLength = lcs (s, i + 1, t, j + i, mem, len+1);
  } else {
    maxLength = max(lcs(s, i, t, j + i, mem, len), lcs(s, i + 1, t, j, mem, len));
  }
  mem[i][j] = maxLength;
}

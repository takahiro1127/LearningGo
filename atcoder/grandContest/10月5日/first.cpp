#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  int k;
  cin >> s;
  cin >> k;
  size_t size = s.length();
  int count  = 0;
  int minimum = 0;
  for (int i = 0; i < size - 1; i++) {
    if (s[i] == s[i+1]) {
      count++;
    } else {
      if (count == 0) {
        continue;
      } else {
        if ((count + 1)%3 == 0) {
          minimum += (count + 1) / 3;
        } else {
        minimum += (count + 1) / 3 + 1;
        }
        count = 0;
      }
    }
  }
  int firstCount = 0;
  if (s[size - 1] == s[0] && count != size - 1) {
    for (int i = 0; i < size - 1; i++) {
      if (s[i] == s[i + 1]) {
        firstCount++;
      } else {
        break;
      }
    }
    if ((firstCount + count + 2) % 3 == 0) {
      minimum += (firstCount + count + 2) / 3;
    } else {
      minimum += (firstCount + count + 2) / 3 + 1;
    }
    cout <<  minimum * k - (firstCount + count + 2) / 3 + (count + 1) / 3 << endl;;
  } else if (count != size - 1) {
    cout << minimum * k << endl;
  } else {
    cout << "ここ" << endl;
    cout << (size * k) / 3 << endl;
  }
}

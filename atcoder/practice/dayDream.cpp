#include<iostream>
#include <string>

using namespace std;

bool search(string, int);

int main()
{
  string s;
  cin >> s;
  fputs(search(s, 0) ? "YES" : "NO", stdout);
  return 0;
}

bool search(string s, int i) {
  if (s.size() < i)
  {
    return false;
  } else if (s.size() == i) {
    return true;
  }
  bool match = false;
  if (s.substr(i, 5) == "dream")
  {
    if (s.substr(i, 7) == "dreamer") {
      match = search(s, i + 5) || search(s, i + 7);
    } else {
      match = search(s, i + 5);
    }
  } else if (s.substr(i, 5) == "erase") {
    if (s.substr(i, 6) == "eraser")
    {
      match = search(s, i + 4) || search(s, i + 6);
    }
    else
    {
      match = search(s, i + 5);
    }
  } else {
    match = false;
  }
  return match;
}

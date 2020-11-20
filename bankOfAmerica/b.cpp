#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
vector<string> split(const string& src, const char* delim = ",") {
    vector<string> vec;
    string::size_type len = src.length();

    for (string::size_type i = 0, n; i < len; i = n + 1) {
        n = src.find_first_of(delim, i);
        if (n == string::npos) {
            n = len;
        }
        vec.push_back(src.substr(i, n - i));
    }

    return vec;
}
int main() {
  vector<string> line_spl;
  vector<vector<int> > point_rows;
  string line;
  int index = 0;
  while (getline(cin, line)) {
    line_spl = split(line, " ");
    int count =  line_spl.size();
    for (int i = 0; i < count; i++) {
      point_rows[index].push_back(stoi(line_spl[i]));
    }
    index++;
  }
  cout << point_rows[0][0] << endl;
}
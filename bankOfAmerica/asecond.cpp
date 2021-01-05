#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
using namespace std;
string map_to_string(map<int, int> int_pairs) {
  string ans;
  map<int, int>::iterator ite;
  for (ite = int_pairs.begin(); ite != int_pairs.end(); ite++) {
      cout << ans << endl;
      ans = ans + to_string(ite->first) + ", " + to_string(ite->second) + ";";
  }
  return ans;
}
int main() {
  string line;
  cin >> line;
    int x;
    std::stringstream ss(line);
    std::string buf;
    int index = 0;
    while (std::getline(ss, buf, ';')) {
      if (index == 1) {
        x = stoi(buf);
      }
      index ++;
    }
    vector<int> numbers;
    // 冗長ですが、使い方あんまり知らないので、再宣言
    std::stringstream sss(line);
    std::string buff;
    while (std::getline(sss, buff, ';')) {
      numbers.push_back(stoi(buf));
    }
    
    // mapにのkey与えられた数列、valueをtrueにします。
    vector<int>::iterator ite;
    map<int, bool> existance;
    for (ite = numbers.begin(); ite != numbers.end(); ite++) {
      existance.insert(make_pair(*ite, true));
    }
    cout << map[1] ? 'true': 'fakse' << endl;
    
    // vectorを再探索し、x-*iteがexistanceにあるかを確認します。
    // あった場合は、答えのpairに入れて、existanceの値を両方ともfalseにします。
    map<int, int> ans;
    for (ite = numbers.begin(); ite != numbers.end(); ite++) {
      if (!existance[*ite]) {
        continue;
      }
      map<int, bool>::iterator position = existance.find(x - *ite);
      if (position != existance.end()) {
        ans.insert(make_pair(*ite, x - *ite));
        existance[x - *ite] = false;
        existance[*ite] = false;        
      }
    
    // 答えを出力します。
    string ans_string = map_to_string(ans);
    cout << ans_string << endl;
  }
}
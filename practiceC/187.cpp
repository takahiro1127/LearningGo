#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map> // ヘッダファイルインクルード
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    // !付きの場合はtrue
    map<string, bool> s;
    bool ans = false;
    string ans_word;
    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        if (ans) {
            continue;
        }
        bool word_contain = word[0] == '!';
        string pure_word = word_contain ? word.erase(0, 1) : word;
        // 初めて見つけた場合
        if (s.find(pure_word) == s.end()) {
            if (word_contain) {
                s.insert(make_pair(pure_word, true));
            } else {
                s.insert(make_pair(pure_word, false));
            }
        } else {
            if (s[pure_word] == !word_contain) {
                ans_word = pure_word;
                ans = true;
            }
        }
    }
    if (ans) {
        cout << ans_word << endl;
    } else {
        cout << "satisfiable" << endl;
    }
}
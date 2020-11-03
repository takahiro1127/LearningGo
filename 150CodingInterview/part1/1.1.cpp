#include <iostream>
#include <algorithm>
#include <string>
#include <map> // ヘッダファイルインクルード
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
// 1.1
int main() {
    map<char, bool> used_alphabet;
    for (char alphabet = 'a'; alphabet <= 'z'; alphabet++)
    {
        used_alphabet[alphabet] = true;
    }
    string used_word = "avs";

    string::iterator it;
    for (it = used_word.begin(); it != used_word.end(); it++)
    {
        cout << *it;
        cout << "\n";
    }
    cout << endl;
    // cout << used_word.end() << endl;
    // const char* memory = used_word.c_str();
    // cout << memory << endl;
    // cout << *memory << endl;

    // int i = 123;
    // int *j = &i;
    // cout << *j;
    // cout << j << endl;

}
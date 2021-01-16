#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map> // ヘッダファイルインクルード
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

bool include_seven(string n) {
    bool ans = false;
    for (int i = 0; i < n.length(); i++) {
        if (n.substr(i, 1) == "7") {
            ans = true;
            break;
        }
    }
    return ans;
}

// 進数の変換
string fromIntToNAry(int n, int base)
{
    string r;
    while (n != 0){
        r += to_string(n % base);
        n /= base;
    }
    return r;
}

int main() {
    int n;
    cin >> n;
    int count = 0;
    for (int i = 1; i <= n; i++) {
        // n以下で、10進数の格桁に7がなくて、8進数の格桁にも7がない数字のカウント
        if (!include_seven(to_string(i)) && !include_seven(fromIntToNAry(i, 8))) {
            count++;
        }
    }
    cout << count << endl;
}
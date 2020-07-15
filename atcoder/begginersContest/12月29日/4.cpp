#include<iostream>
using namespace std;
int n, k, r, s, p;
string t;
int main() {
    cin >> n >> k;
    cin >> r >> s >> p;
    cin >> t;
    bool a[n];//あいこになったらtrueにする
    for (int i = 0; i < n; i++) {
        a[i] = false;
    }
    int score = 0;
    for (int i = 0; i < n; i++) {
        if (i >= k && t[i] == t[i - k] && !a[i - k]) {
            a[i] = true;
            continue;
        }
        if (t[i] == 'r') {//pでかつ
            score += p;
        } else if (t[i] == 's') {//rでかつ
            score += r;
        } else {//sでかつ
            score += s;
        }
    }
    cout << score << endl;
}
//必ず勝利以上にはできる

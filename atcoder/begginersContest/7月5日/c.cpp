#include<iostream>
using namespace std;
int h, w, k;
bool c[6][6];//白がfalse 黒がtrue
int ans = 0;
#define rep(i, n) for(int i = 0; i < (n); i++)
void count(bool sh[], bool sw[]) {
    int counting = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (c[i][j] && !sh[i] && !sw[j]) {
                counting += 1;
            }
        }
    }
    if (counting == k) {
        ans += 1;
    }
    return;
}
//horwはhならtrue, wならfalse
void search(bool sh[], bool sw[], int num, bool horw) {
    if (num == w && !horw) {
        count(sh, sw);
        return;
    }
    if (num == h && horw) {
        horw = false;
        num = -1;
    }
    if (horw) {
        search(sh, sw, num + 1, true);
        sh[num] = true;
        search(sh, sw, num + 1, true);
        sh[num] = false;
    } else {
        search(sh, sw, num + 1, false);
        if (num == -1) {
          sw[0] = true;
        } else {
          sw[num] = true;
        }
        search(sh, sw, num + 1, false);
        if (num == -1) {
          sw[0] = false;
        } else {
          sw[num] = false;
        }
    }
}

int main() {
    bool sh[6], sw[6];//塗りつぶしたらtrue
    cin >> h >> w >> k;
    for (int i = 0; i < h; i++) {
        string s;
        cin >> s;
        sh[i] = false;
        for (int j = 0; j < w; j++) {
          sw[j] = false;
          if (s.substr(j, 1)  == ".") {
            c[i][j] = false;
          } else {
            c[i][j] = true;
          }
        }
    }
    search(sh, sw, 0, true);
    cout << ans / 2 << endl;
}

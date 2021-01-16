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
    ll startX;
    ll goalX;
    ll startY;
    ll goalY;
    cin >> startX;
    cin >> startY;
    cin >> goalX;
    cin >> goalY;
    goalX -= startX;
    goalY -= startY;
    //y = x と y = -x　を表すベクトルは線形独立なので1回もしくは2回でたどり着く事ができる。
    //※重なっている場合は0回
    if (goalX == 0 && goalY == 0) {
        cout << "0" << endl;
    // 一回で移動できる場合
    } else if (abs(goalX) == abs(goalY) || abs(goalX) + abs(goalY) <= 3) {
        cout << "1" << endl;
    // 足して偶数なら二回で到達可能
    // もしくは、y = xもしくはy = -xの周辺三マスなら2回で移動可能
    //　二回3以内の行動をした場合, 6マスいないならどこでも行けることになる。
    } else if ((goalX + goalY) % 2 == 0 || abs(goalY - goalX) <= 3 || abs(goalY + goalX) <= 3 || abs(goalX) + abs(goalY) <= 6) {
        cout << "2" << endl;
    } else {
        cout << "3" << endl;
    }
}
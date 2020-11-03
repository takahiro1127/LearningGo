#include <iostream>
#include <algorithm>
#include <string>
#include <map> // ヘッダファイルインクルード
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
// 2.5
int main()
{
    // 1 * 先頭　+ 10 * 二番目...とforで数に直す
    // 足し合わせる
    // %10, %100 - %10と言った具合で連結リストにいれる
    // または、同時に先頭から取り出し、足し合わせた物をどんどん格納していく
    // 前回繰り上げがあったものは、true, falseで管理する。

    //　双方向なら上のくらいからとか関係ない
    // 単に連結ならば、上のくらいから出して、10を超えたら一つ前の要素に1を加える。
    // 最後まで足しまくって、超えてしまった場合はpush frontする
}
#include <iostream>
#include <algorithm>
#include <string>
#include <map> // ヘッダファイルインクルード
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
// 1.5
int main()
{
    // 簡単な方法　→　全探索
    // 文字数の差に応じて操作を変更
    // 一方の文字数が多い場合　→　前から比較し、文字数が多い方だけ違った場合は走査はスキップ → 全部比較が==となる
    // 同じ場合 →　前から比較し、違う場合を一回のみ許容　→　全ての比較が==となる
}
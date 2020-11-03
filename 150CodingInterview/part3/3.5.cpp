#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map> // ヘッダファイルインクルード
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
// 3.5
int main()
{
    // stack以外のデータ構造を使わずに、
    // push, pop, top, emptyのみを使って、
    // stackの並び替えアルゴリズムを作成
    // 使っていいstackも該当以外だと一つだけ
    // stackを順番に取り出し、もう片方のstackに入れていく
    // 一番大きかった値のみ入れずに保持しておく
    // 最大値が更新されるたびに、それまでの最大値をもう片方のstackにいれることによって、これを実現
    // 残った最大値を空になったstackにいれる。
    // 移し終えた方のstackから同じ形でstackの中身を移動
    // ここで、最大値-適当なstack 空, 別でintに二(n)番目の最大値を保持
    // からのstackからもう片方のstackに一気に移し替える。
    // 二番目の最大値 < 次に移し替える値　となったタイミングで二(n)番目の最大値をいれる
    // これによって、　適当なstack-二(n)番目の最大値-最大値 となる。
    // これを繰り返すことで、sortができる
}
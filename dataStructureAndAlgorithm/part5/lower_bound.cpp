#include <iostream>
#include <algorithm>

using namespace std;

// イテレータ
// コンテナの特定の位置を扱う物
//　ポインタの様に扱う事ができる

void main() {
    int A[14] = {1, 1, 2, 2, 2, 4, 5, 5, 6, 8, 8, 8, 10, 15};
    int *pos;
    int idx;
    pos = lower_bound(A, A + 14, 4);
    // ソートされた範囲に対するアルゴリズム
    //　指定された値以上の最初の要素の位置をイテレータで返す
    idx = distance(A, pos);
    // distanceは二つのポインタの距離を返す関数
}
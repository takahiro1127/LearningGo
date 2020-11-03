#include<iostream>
#include<vector>

using namespace std;

// イテレータ
// コンテナの特定の位置を扱う物
//　ポインタの様に扱う事ができる

void print(vector<int> v) {
    vector<int>::iterator it;
    for (it = v.begin(); it != v.end(); it++) {
        cout << *it;
    }
    cout << endl;
}
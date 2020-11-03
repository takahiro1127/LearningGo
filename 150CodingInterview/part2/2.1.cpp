#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <list>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
// 2.1
int main()
{
    int n = 100;
    list<int> lst(n);
    lst.push_front(1);
    lst.push_back(233);
    list<int>::iterator adress;
    for (adress = lst.begin(); adress != lst.end(); adress++)
    {
        cout << *adress << endl;
    }

    // 簡単な方法としては、map<int, bool>を作成して、trueの場合そのlinked_listを削除
    // 発展問題の場合
    // sortしてから削除 もしくは sortしながら削除
    // もしくは一番後ろの値をnとして、一番後ろ一歩手前まで走査、nと同じものを削除
    // これを繰り返すとn^2のアルゴリズムになる
}
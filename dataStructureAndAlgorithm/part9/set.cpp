#include <iostream>
#include <set>

using namespace std;
void main()
{
    //要素が値によってソートされている集合
    //挿入されたソートは集合の中に唯一存在するので、重複しない
    set<int> S;
    S.insert(8);
    S.insert(9);
    S.insert(10);
    S.insert(7);
    set<int>::iterator = it;
    for (it = S.begin(); it != S.end(); it++)
    {
        cout << *it << endl;
    }
}
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <map> // ヘッダファイルインクルード
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
// 2.8
int main()
{
    // map<list<int>::iterator, bool>で判定をする
    list<int> lst(5);
    lst.push_front(1);
    lst.push_front(2);
    lst.push_front(3);
    lst.push_front(4);
    lst.push_front(5);

    list<int>::iterator adress;
    // ↓これはできない
    // 一つ目の理由としてlistにoperator >を実装していないから
    // またconst keyではないから
    // map<list<int>::iterator, bool> mp;

    // 値をkeyに持って、ポインタの配列をvalueに持つmapを作成
    // 重複するkeyを見つけた場合、ポインタを前から順番に比較
    // 重複した場合それが最初の要素
    // vector<list<int>::iterator> vec;
    map<int, vector<list<int>::iterator> > mp;
    for (adress = lst.begin(); adress != lst.end(); adress++)
    {
        // vec.push_back(adress);
        // mp[*adress].push(adress);
        if (mp.count(*adress)) {
            mp.find(*adress)->second.push_back(adress);
        } else {
            vector<list<int>::iterator> temp_vec;
            temp_vec.push_back(adress);
            mp.insert(make_pair(*adress, temp_vec));
        }
    }
    map<int, vector<list<int>::iterator> >::iterator ite;
    for (ite = mp.begin(); ite != mp.end(); ite++) {
        cout << ite->first << " must equal ";
        vector<list<int>::iterator>::iterator vec_ite;
        for (vec_ite = ite->second.begin(); vec_ite != ite->second.end(); vec_ite++)
        {
            // 一つ目の*でvector::iteratorの値の中身である、list::iteratorを出す。
            // 二つ目の*でlist::iteratorの中身であるintを出す。
            cout << **vec_ite << " ";
        }
        cout << endl;
    }
    // 毎回このvectorの中を探索することになるので、


    // iterator
}
#include <iostream>
#include <set>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
// 二分木と貪欲砲greedyを組み合わせたアルゴリズム
//　蟻本のp50のfence repair

int main() {
    multiset<int> s;
    s.insert(3);
    s.insert(2);
    s.insert(1);
    s.insert(3);
    s.insert(4);
    s.insert(4);
    s.insert(4);
    s.insert(5);
    s.insert(2);

    size_t count = s.count(3);
    cout << "s contains " << count << " 3s" << endl;

    decltype(s)::iterator place = s.find(3);
    for (; place != s.end(); place++)
    {
        cout << *place << endl;
    }
}
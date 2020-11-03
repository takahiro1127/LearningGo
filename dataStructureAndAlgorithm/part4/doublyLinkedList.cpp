#include <iostream>
#include <list>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    list<int> lst(n);
    rep(i, n - 5) lst.push_front(i);
    for (auto iter = lst.begin(); iter != lst.end(); iter++) {
        *iter = 99;
    }
    rep(i, 5) lst.push_back(i);
    for (auto iter = lst.begin(); iter != lst.end(); ++iter) {
        cout << *iter << endl;
    }
}
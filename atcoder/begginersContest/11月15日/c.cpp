#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)
int n, k;

bool check(vector<int> visit_order, vector<vector<ll> >& t) {
    ll routeCost = 0;
    vector<int>::iterator vite = visit_order.begin();
    vector<int>::iterator previous_vite = visit_order.end();
    previous_vite--;
    for (; vite != visit_order.end(); vite++) {
        routeCost += t[*previous_vite][*vite];
        previous_vite = vite;
    }
    return routeCost == k;
}

int main()
{
    cin >> n >> k;
    vector<vector<ll> > t(n, vector<ll>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> t.at(i).at(j);
        }
    }
    // 8!通りを並べて、経路として可能かどうか
    // 合計はkになるかを確認する
    vector<int> nodes;
    for (int i = 0; i < n; i++) {
        nodes.push_back(i);
    }
    ll ans = 0;
    do {
        if (check(nodes, t)) {
            ans++;
        }
    } while (std::next_permutation(nodes.begin(), nodes.end()));
    cout << ans / n << endl;
}

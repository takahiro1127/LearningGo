#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    std::vector<int> p(n);
    rep(i, n) cin >> p[i];
    int min = p[0];
    int max_diff = -200001;
    for (int i = 1; i < n; i++) {
        int diff = p[i] - min;
        if (max_diff < diff) {
            max_diff = diff;
        }
        if (p[i] < min) {
            min = p[i];
        }
    }
    cout << max_diff << endl;
}
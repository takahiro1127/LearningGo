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
    for (int i = 0; i < n; i++) {
        int min_position = i;
        int min = p[i];
        for (int j = i + 1; j < n; j++)
        {
            if (min > p[j]) {
                min = p[j];
                min_position = j;
            }
        }
        swap(p[i], p[min_position]);
    }
    rep(i, n) cout << p[i] << endl;
}
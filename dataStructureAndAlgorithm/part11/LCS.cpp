#include <iostream>
#include <set>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;
string x, y;
int j, k;
int ans[1000][1000];
bool solved[1000][1000];

void solve(int x_index, int y_index)
{
    if (solved[x_index][y_index]) {
        return ans[x_index][y_index];
    }
    if (x_index == 0 && y_index == 0) {
        return x[0] == y[0] ? 1 : 0;
    }
    return x[x_index] == y[y_index] ? ans[x_index][y_index] + 1 : max(ans[x_index][y_index - 1], ans[x_index - 1][y_index]);
}

void main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        cin >> y;
        j = x.length();
        k = y.length();
        for (int l = 0; l < j; l++)
        {
            for (int m = 0; m < k; m++) {
                ans[l][m] = solve(l, m);
                solved[l][m] = true;
            }
        }
        cout << ans[j - 1][k - 1];
    }
}
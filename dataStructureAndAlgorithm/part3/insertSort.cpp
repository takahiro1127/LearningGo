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
    for (int i = 1; i < n; i++)
    {
        int insert = p[i];
        for (int j = i - 1; j >= 0; j--)
        {
            if (insert < p[j]){
                p[j + 1] = p[j];
            } else {
                p[j + 1] = insert;
                break;
            }
        }
    }
    rep(i, n) cout << p[i] << endl;
}
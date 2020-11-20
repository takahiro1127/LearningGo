#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)


int main()
{
    long double x, y, x1, y1;
    cin >> x >> y >> x1 >> y1;
    long double ans = (x1 - x) * y / (y + y1) + x;
    cout << fixed << setprecision(15) << ans << endl;
}
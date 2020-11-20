#include <iostream>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
bool onLine(int x, int y, int xj, int yj) {
    if (x == 0) {
        return xj == 0 || y == 0;
    }
    if (xj == 0)
    {
        return x == 0 || yj == 0;
    }
    if (yj == 0)
    {
        return y == 0 || xj == 0;
    }
    if (y == 0)
    {
        return yj == 0 || x == 0;
    }
    if (x < xj) {
        return abs(y) < abs(yj) && yj * y > 0 && (xj % x == 0) && (yj % y == 0) && ((xj / x) == (yj / y));
    }
    else if (xj < x) {
        return abs(yj) < abs(y) && yj * y > 0 && (x % xj == 0) && (y % yj == 0) && ((x / xj) == (y / yj));
    } else {
        if (x == xj) {
            return yj == y;
        } else {
            return x == -1 * xj && y == -1 * yj;
        }
    }
}

// 傾きで判断できる！！！！！！

bool onLine(int x, int y, int xi, int yi, int xj, int yj) {
    if (x <= xi && x <= xj) {
        return onLine(xi - x, yi - y, xj - x, yj - y);
    }
    else if (xi <= x && xi <= xj)
    {
        return onLine(x - xi, y - yi, xj - xi, yj - yi);
    }
    else
    {
        return onLine(xi - xj, yi - yj, x - xj, y - yj);
    }
}

int main()
{
    int n;
    cin >> n;
    int a[100], b[100];
    rep(i, n) cin >> a[i] >> b[i];
    bool ans = false;
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                if (onLine(a[i], b[i], a[j], b[j] ,a[k], b[k]))
                {
                    ans = true;
                    break;
                }
            }
        }
    }
    if (ans) {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}

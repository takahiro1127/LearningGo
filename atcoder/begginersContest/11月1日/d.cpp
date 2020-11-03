#include <iostream>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)
bool devidable(int n) {
    return n % 8 == 0;
}
int main()
{
    string s;
    cin >> s;
    string hj = s;
    bool ans = false;
    if (s.size() == 1) {
        ans =  devidable(stoi(s));
    }
    if (s.size() == 2) {
        ans = devidable(stoi(s.substr(0, 1)) * 10 + stoi(s.substr(1, 1))) || devidable(stoi(s.substr(1, 1)) * 10 + stoi(s.substr(0, 1)));
    }
    hj.erase(unique(hj.begin(), hj.end()), hj.end());
    // ここで、文字列の足し算で条件を満たす形にすればよかった。
    if (hj.size() == 1)
    {
        if (s.count(hj) >= 3)
        {
            devidable(stoi(hj.substr(i, 1)) * 100 + stoi(hj.substr(j, 1)) * 10 + stoi(hj.substr(k, 1)))
        }
        else if (s.count(hj) == 2)
        {

        }
    }
    else if (k.size() == 2)
    {
    }
    int len = s.size();
    for (int i = 0; i < len; i++)
    {
        if (ans) {
            break;
        }
        for (int j = 0; j < len; j++) {
            if (j == i) {
                continue;
            }
            for (int k = 0; k < len; k++) {
                if (k == i || k == j) {
                    continue;
                }
                if (devidable(stoi(s.substr(i, 1)) * 100 + stoi(s.substr(j, 1)) * 10 + stoi(s.substr(k, 1))))
                {
                    ans = true;
                    break;
                }
            }
        }
    }
    if (ans)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}

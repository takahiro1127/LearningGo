#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
int main() {
    string c;
    cin >> c;
    if (c[0] == c[1] && c[1] == c[2]) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
}

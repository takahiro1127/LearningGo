#include<iostream>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
int main() {
    char s;
    cin >> s;
    if (isupper(s)) {
        cout << 'A' << endl;
    } else {
        cout << 'a' << endl;
    }
}

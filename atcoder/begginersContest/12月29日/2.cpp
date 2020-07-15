#include<iostream>
using namespace std;
long int a, b, k;
int main() {
    cin >> a >> b >> k;
    if (a > k) {
        cout << a - k << " " << b << endl;
    } else {
        long int rest = b - (k - a);
        if (rest > 0) {
            cout << 0 << " " << rest << endl;
        } else {
            cout << 0 << " " << 0 << endl;
        }
    }
}

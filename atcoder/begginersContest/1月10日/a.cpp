#include<iostream>
using namespace std;
int k, x;
int main() {
    cin >> k >> x;
    if (500 * k >= x) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

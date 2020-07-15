#include<iostream>
using namespace std;
int A, B;
int main() {
    cin >> A;
    cin >> B;
    if (A == 1) {
        if (B == 2) {
            cout << 3 << endl;
        } else {
            cout << 2 << endl;
        }
    } else if (A == 2) {
        if (B == 3) {
            cout << 1 << endl;
        } else {
            cout << 3 << endl;
        }
    } else {
        if (B == 2) {
            cout << 1 << endl;
        } else {
            cout << 2 << endl;
        }
    }
}

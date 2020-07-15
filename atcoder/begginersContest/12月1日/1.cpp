#include<iostream>
using namespace std;

int main() {
    int m1, m2, d1, d2;
    cin >> m1 >> d1 >> m2>> d2;
    if (m2 - m1 == 1) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }
}

bool exist;
    exist = false;
    for (int i = 100; i < 106 || !exist; i++) {
        int k;
        k = x - i;
        if (a[k] == 2) {
            a[k] = search(k);
            exist = a[k];
        } else if (a[k] == 1) {
            return true;
        } else if (a[k] == 0) {
            continue;
        }
    }

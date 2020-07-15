#include<iostream>
using namespace std;
int main() {
    int a, b, x, midint;
    cin >> a >> b >> x;
    double max, min, mid;
    max = x;
    min = 0;
    for (int i = 0; i < 100; i++) {
        if ((max + min)/ 2 == mid) {
            break;
        }
        mid = (max + min)/ 2;
        midint = mid;
        if (x > a * mid + b * to_string(midint).length()) {
            min = mid;
        } else {
            max = mid;
        }
    }
    if (midint < 1000000000) {
        cout << midint << endl;
    } else {
        cout << 1000000000 << endl;
    }
}

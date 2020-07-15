#include<iostream>
using namespace std;

int main() {
    double n;
    cin >> n;
    int c;
    c = n;
    int x;
    x = (n * 100)/ 108;
    bool exist;
    exist = false;
    x = x - 10;
    for (;x * 1.08 <= c + 1;x++) {
        int y;
        y = x * 1.08;
        if (y == c) {
            exist = true;
            cout << x << endl;
            break;
        }
    }
    if (!exist) {
        cout << ":("<< endl;
    }
}

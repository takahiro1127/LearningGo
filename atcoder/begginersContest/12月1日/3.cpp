#include<iostream>
using namespace std;
int x;
int a[100000];//初期値は0なので、0が未探索、1が訪問済みでtrue、2が訪問済みでfalse
bool search(int);
int main() {
    cin >> x;
    cout << search(x) << endl;
}

bool search(int x) {
    if (x == 0 || x == 100 || x == 101 || x == 102 || x == 103 || x == 104 || x == 105) {
        return true;
    } else if (x < 100) {
        return false;
    }
    for (int i = 100; i < 106; i++) {
        int k = x - i;
        if (a[k] == 1) {
            return true;
        } else if (a[k] == 0) {
            a[k] = search(k);
            if (a[k]) {
                return true;
            } else {
                a[k] = 2;
            }
        }
    }
    return false;
}

#include<iostream>
using namespace std;
int n;
int main() {
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int count = 0;
    bool enter = false;
    int m = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = m; j < n; j++) {
            if (a[j] == i) {
                enter = true;
                m = j+1;
                count++;
                break;
            }
            if (j == n - 1) {
                goto OUT;
            }
        }
    }
    OUT:
    if (!enter) {
        cout << "-1" << endl;
    } else {
        cout << n - count << endl;
    }
}

//前から順番に1, 2, 3と見つけていくことができればいい
//この時一番長くなるようにすればいい

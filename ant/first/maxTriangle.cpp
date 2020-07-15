#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j > i; j--) {
            if (a[j] > a[j - 1]) {
                swap(a[j], a[j - 1]);
            }
        }
    }
    for (int i = 0; i < n-2; i++) {
        if(a[i] - a[i + 1] - a[i + 2] < 0) {
            cout << a[i] + a[i + 1] + a[i + 2] << endl;
            break;
        }
        if (i == n - 2) {
            cout << 0 << endl;
        }
    }
    return 0;
}

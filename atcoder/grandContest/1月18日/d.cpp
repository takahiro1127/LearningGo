#include<iostream>
using namespace std;
int n;
int a[18], b[18];
void f(int, int);
bool resolve(int);
//  
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    int count = 0;
    int k[n];
    for (int i = 0; i < n; i++) {
        k[i] = 0;
    }
    solve(k[i], 0);
    cout << count << endl;
}
int solve(k) {

}

bool resolve(int i) {
    if (a[i] <= b[i+1]) {

    }
}

bool c() {
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            return false;
        }
    }
    return true;
}

void f(int i) {
    int j = i + 1;
    swap(a[i], a[j]);
    swap(b[i], b[j]);
    swap(a[i], b[i]);
    swap(a[j], b[j]);
}

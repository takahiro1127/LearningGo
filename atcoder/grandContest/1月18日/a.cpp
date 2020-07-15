#include<iostream>
using namespace std;
int h, w, n;
int main() {
    cin >> h;
    cin >> w;
    cin >> n;
    int k = max(h, w);
    if (n % k == 0) {
        cout << n / k << endl;
    } else {
        cout << n / k + 1  << endl;
    }
}

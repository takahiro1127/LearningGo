// a0~an-1と整数sについて連続する部分列でその総和がS以上となるもののうち最小の長さ
#include<iostream>
using namespace std;
int n, S, min;
int main() {
    cin >> n >> S;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int sum, minLength, t;
    t = 0;
    for (int i = 0; i < n; i++) {
        for (int j = t; j < n; j++) {
            t = j;
            sum += a[j];
            if (sum > S) {
                if (minLength > j - i) {
                    minLength = j - i;
                }
                break;
            }
        }
        sum -= a[i];
    }
}

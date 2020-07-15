#include<iostream>
using namespace std;

int main() {
    int n, k, count;
    count = 0;
    cin >> n >> k;
    int a[n], sum[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sum[0] = a[0];
    for (int i = 1; i < n; i++) {
        sum[i] = sum[i - 1] + a[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int right;
            if (i == 0) {
                right = sum[j];
            } else {
                right = sum[j] - sum[i - 1];
            }
            if (j + 1 - i== right % k) {
                count+=1;
            }
        }
    }
    cout << count << endl;
}

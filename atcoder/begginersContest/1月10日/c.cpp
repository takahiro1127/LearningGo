#include<iostream>
using namespace std;
int n;
int p[8], q[8];
int main() {
    cin >> n;
    int k = 1;
    for (int i = 1; i < n; i++) {
        k *= i;
    }
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> q[i];
    }
    int pc = 0;
    int qc = 0;
    int pk = k;
    int qk = k;
    for (int i = 0; i < n - 1; i++) {
        pc += (p[i] - 1) * pk;
        pk /= n - i - 1;
    }
    for (int i = 0; i < n - 1; i++) {
        qc += (q[i] - 1) * qk;
        qk /= n - i - 1;
    }
    cout << abs(pc - qc) << endl;
}
// 全列挙で大丈夫だった！！！全列挙を可能性に入れて考えよう！！

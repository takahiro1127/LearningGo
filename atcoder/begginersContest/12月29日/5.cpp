#include<iostream>
using namespace std;
int n, m;
int main() {
    int A[n];
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    sort(A, A + n);
    int B[n];//一番最小のペアのindex
    for (int i = 0; i < n; i++) {
        B[i] = m - 1;
    }
    int score;
    int k, l;//kは固定数　lは下をみていく
    k = m - 1;
    l = m - 2;
    bool pk, pl, pscore;
    pk = true;
    pl = false;
    pscore = true;
    for (int i = 0; i < m; i++) {
        if (pk) {
            score += A[k] * 2;
            pk = false;
        } else if (pl) {
            score += A[k] + A[l];
            pscore = !pscore;

        }
    }
    cout << score << endl;
}

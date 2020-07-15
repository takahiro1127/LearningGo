//m*nのタイル
//マスをひっくり返して、すべて白にしたい
//不器用だからひくり返すときに縦横の隣接するタイルもひっくり返る
//出来るだけ早くすべてのマスを白にしたい
#include<iostream>
#include<Eigen/Core>
using namespace std;
int n, m;
MatrixXint reverse(MatrixXint, int, int);
void fromDecideFirstRowToSolve(MatrixXint, int);
int main() {
    cin >> n >> m;
    MatrixXint T(n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> T(i, j);
        }
    }
    //最初の行をどのようにひっくり返すかの話
    fromDecideFirstRowToSolve(T, 0);
}

int fromDecideFirstRowToSolve(MatrixXint T, int k) {
    if (k == n) {
        return solve(T, 1, 0);
    }
    return min(fromDecideFirstRowToSolve(T, k + 1), fromDecideFirstRowToSolve(reverse(T, k, 0), k + 1));
}

int solve(MatrixXint T, int retu, int count) {
    for (int i = 0; i  < n; i++) {
        if (T(retu - 1, i) == 1) {
            T = reverse(T, retu, i);
            count++;
        }
    }
    if (retu == m - 1) {
        return T.dot(T) == 0 ? n * m * 2 : count;
    }
    solve(T, retu + 1);
}

MatrixXint reverse(MatrixXint T, int i, int j) {
    T(i, j) == 0 ? 1 : 0;
    T(i - 1, j) == 0 ? 1 : 0;
    T(i, j - 1) == 0 ? 1 : 0;
    T(i + 1, j) == 0 ? 1 : 0;
    T(i, j + 1) == 0 ? 1 : 0;
    return T;
}

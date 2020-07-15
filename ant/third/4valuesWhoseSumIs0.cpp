//要素数nの整数の配列A, B, C, Dについて
//各リストから一つずつ取り出したときその和が０となるような組み合わせの個数
//ただし1つのリストに同じ値が複数含まれている場合、それらは異なる物として考える
#include<iostream>
#include<Eigen/Core>
using namespace std;
int n;
int main() {
    cin >> n;
    MatrixXint X(4, n);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < n; j++) {
            cin >> X(i, j);
        }
    }
    
}



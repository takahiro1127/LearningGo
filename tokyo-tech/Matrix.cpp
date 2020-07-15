//20M14552
//上原隆寛
#include<iostream>
#include <algorithm>
using namespace std;
typedef unsigned long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
int personID;
class Matrix {
};
class IdMatrix: public Matrix {
    Matrix mul(Matrix multipleMatrix) {
        return multipleMatrix;
    };
    Matrix add(Matrix additionalMatrix) {
        rep(i, Martix.rows()) additionalMatrix[i][i]++;
        return additionalMatrix;
    };
};

#include<iostream>
#include<Eigen/Dense>
using namespace std;
using namespace Eigen;
typedef unsigned long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
//問題条件
double r = 1.2;
double lambda = 0.5;
//data importによって変化
ll N;
MatrixXd covariance = MatrixXd::Random(N, N);
VectorXd exReturn = VectorXd::Random(N);
VectorXd x = VectorXd::Random(N);
vector<vector<double>> data;

void fit() {
    VectorXd y = exReturn * covariance;
}
vector ReadCsv() {
    vector<vector<ll>> data;
    // data = getFromCsv();
    //具体的なロジックは一旦むし
    return data;
}
void importDate() {
    //readCsv and stock data as variables;
    //銘柄nの実現収益率を保持する
    //data = [[time = 0, 銘柄1の期待収益, 銘柄2の期待収益, ....銘柄nの期待収益], [time = 1]];
    data = getReturnRateFromPrice(ReadCsv());
    //init matrix and vectors;
    N = data[0].length();
    covariance = MatrixXd::Random(N, N);
    exReturn = VectorXd::Random(N);
    x = VectorXd::Random(N);
}
int main() {
    importData();
    rep(i, n) fit();
}
